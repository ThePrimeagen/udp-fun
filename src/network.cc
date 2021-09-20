#include <node.h>
#include <uv.h>
#include <iostream>
#include "network-udp.hpp"

namespace fun_network_program {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void TestUv(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(v8::Undefined(isolate));

    // kick off a thread
    Local<v8::Function> callback = Local<v8::Function>::Cast(args[1]);

    auto looper = new foo::UdpStuff();
}

void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "test_uv", TestUv);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo


