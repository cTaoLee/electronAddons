// test.cc
#include <node.h>

namespace demo {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void Method(const FunctionCallbackInfo<Value>& args) {
	  Isolate* isolate = args.GetIsolate();

	  Local<Object> obj = Object::New(isolate); // 创建对象 obj
	  obj->Set(String::NewFromUtf8(isolate, "msg"), args[0]->ToString());// 相当于 obj.msg = arguments[0];
	  args.GetReturnValue().Set(obj);// 返回这个对象
	}

	void Init(Local<Object> exports,Local<Object> module) {
	  NODE_SET_METHOD(module, "exports", Method);
	}

	NODE_MODULE(addon, Init)

}  // namespace demo