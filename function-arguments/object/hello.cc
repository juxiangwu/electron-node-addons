#include <node.h>

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
// This is the implementation of the "add" method
// Input arguments are passed using the
// const FunctionCallbackInfo<Value>& args struct
void ComputeArea(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  // Check the number of arguments passed.
  if (args.Length() != 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  // Check the argument types
  if (!args[0]->IsObject()) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  // js Array to v8 Array
    Local<Object> obj = Local<Object>::Cast(args[0]);
	
	double val_w = obj->Get(String::NewFromUtf8(isolate,"width"))->NumberValue();
	double val_h = obj->Get(String::NewFromUtf8(isolate,"height"))->NumberValue();
	
	double area = val_w * val_h;
	Local<Number> num = Number::New(isolate, area);
  // Set the return value (using the passed in
  // FunctionCallbackInfo<Value>&)
  args.GetReturnValue().Set(num);
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "computeArea", ComputeArea);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Init)

}  // namespace demo