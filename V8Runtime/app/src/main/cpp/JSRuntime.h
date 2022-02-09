//
// Created by 谢荣基 on 2022/1/29.
//

#ifndef V8RUNTIME_JSRUNTIME_H
#define V8RUNTIME_JSRUNTIME_H
#include "jni.h"
#include "v8.h"
#include "Utils.h"

using namespace v8;
class JSRuntime {
public:

    JSRuntime(JNIEnv * env,jobject runtime);
    ~JSRuntime();

    static void Init(JNIEnv * env,jobject runtime,jstring app_root_path,jstring startup_flags);

    static JSRuntime * GetJSRuntime();
    static jobject  GetJavaJSRuntime();



private:

    int InitializeV8Engine();

    JNIEnv * env;
    JavaVM * jvm;
    jobject j_js_runtime;
    static JSRuntime *instance;

    static int isInitialized;

};


#endif //V8RUNTIME_JSRUNTIME_H
