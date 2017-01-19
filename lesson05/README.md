lesson05：返回对象2
===================


```cc
// test.cc
#include <node.h>

namespace demo {

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::FunctionTemplate;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void MyFunction(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "hello world"));
}

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // FunctionTemplate/ObjectTemplate可以理解为JS function和C++ 函数之间的binding
  // 相当于 js 中的 function 和 object
  Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, MyFunction);// 生成v8函数模板
  Local<Function> fn = tpl->GetFunction();

  // 假如没有这一步，会使函数匿名
  fn->SetName(String::NewFromUtf8(isolate, "theFunction"));
  args.GetReturnValue().Set(fn);
}

void Init(Local<Object> exports, Local<Object> module) {
  NODE_SET_METHOD(module, "exports", Method);
}

NODE_MODULE(addon, Init)

}  // namespace demo

```

```js
// test.js
const addon = require('./build/Release/addon');

let fn = addon();

console.log(fn());
```