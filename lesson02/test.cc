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
	void init(Local<Object> exports) {	// 载入模块的exports对象
		// 为输出模块的exports对象设置一个方法 等同 exports.fun = Method;
	  NODE_SET_METHOD(exports, "fun", Method);
	}

	// 输出模块
	NODE_MODULE(addon, init)

}   // namespace demo