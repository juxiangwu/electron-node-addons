#include <node.h>
///#include "boost/array.hpp"

namespace demo {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Number;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
  //boost::array<int,9> arr = {1,2,3,4,5,6,7,8,9};
  
  //Local<Array> v8array = Array::New(isolate); 
  //for(int i = 0;i < 9;i++){
//	  v8array->Set(i,Number::New(isolate,arr[i]));
 // }
 // args.GetReturnValue().Set(v8array);
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "hello", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo