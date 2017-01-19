#include <node.h>

namespace demo {

	using v8::Function;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Null;
	using v8::Object;
	using v8::String;
	using v8::Value;

	// 将函数 Method 的参数（一个函数）做定义
	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		// 定义cb类型是 v8::Function 并为 v8::Function::Cast 的一个实例化
		Local<Function> cb = Local<Function>::Cast(args[0]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
		// V8::Function::Call 相当于 Function.prototype.call
		// 第一个参数定义 function 的this，第二个和第三个定义了 function 的形参
		cb->Call(Null(isolate), argc, argv);
	}

	void Init(Local<Object> exports, Local<Object> module) {
		// 为输出模块的module对象设置exports属性 等同 module.exports = Method;
	  	NODE_SET_METHOD(module, "exports", Method);
	}

	NODE_MODULE(addon, Init)

}  // namespace demo