lesson02：node-gyp 编译流程
===================
> - 注意：本例运行环境为 node(v6.9.2)，更早版本或更新版本代码可能有所不同。

## set 1

`npm init` 新建一个项目，并建一个node-gyp的配置文件 **binding.gyp** （一定要叫这个名字）

```gyp
// binding.gyp
{
  "targets": [
    {
      "target_name": "addon",
      "sources": [ "test.cc" ]
    }
  ]
}

```
##set 2
新建一个要编译的文件**test.cc** (.cc是linux下的c++文件格式)

```cc
// test.cc
#include <node.h>	// 使用尖括号表示在包含文件目录中去查找(包含目录是由用户在设置环境时设置的)
					// 使用双引号则表示首先在当前的源文件目录中查找，若未找到才到包含目录中去查找

namespace demo {

	// 使用前声明
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	// 定义一个叫 Method 的函数，这个函数返回了v8里的string类型的数据 "hello world"
	void Method(const FunctionCallbackInfo<Value>& args) {
	  Isolate* isolate = args.GetIsolate();
	  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world"));
	}


	// 初始化输出模块函数
	void init(Local<Object> exports) { // 载入模块的exports对象
		// 为输出模块的exports对象设置一个方法 等同 exports.fun = Method;
	  	NODE_SET_METHOD(exports, "fun", Method);
	}

	// 输出模块
	NODE_MODULE(addon, init)

}   // namespace demo

```
##set 3
编译 `node-gyp configure build`
##set 4
新建一个js文件**test.js**，用来调用我们编译好的模块
```js
// test.js
var addon = require('./build/Release/addon');

console.log(addon.fun());
```
##set 5
执行 `node index`
