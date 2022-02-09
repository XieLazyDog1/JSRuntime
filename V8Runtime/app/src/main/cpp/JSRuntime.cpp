//
// Created by 谢荣基 on 2022/1/29.
//

#include "JSRuntime.h"

JSRuntime* JSRuntime::instance = nullptr;

int JSRuntime::isInitialized = 0;

JSRuntime::JSRuntime(JNIEnv *env, jobject runtime) {

    JSRuntime::isInitialized = 0;

    // JNIEnv JavaVM JSRuntime.java
    jvm = nullptr;
    this->env = env;
    env->GetJavaVM(&(this->jvm));
    j_js_runtime = runtime;

    // 初始化对Java侧的方法调用ID

    // 初始化V8引擎
    JSRuntime::isInitialized = InitializeV8Engine();
}

JSRuntime::~JSRuntime() {

}

void JSRuntime::Init(JNIEnv *env, jobject runtime, jstring app_root_path, jstring startup_flags) {


    // 获取JSRuntime实例
    JSRuntime::instance = new JSRuntime(env,runtime);

    // 配置参数
//    ::Utils::APP_ROOT_DIR_PATH = app_root_path;



}


int JSRuntime::InitializeV8Engine() {


    ::Utils::loge("V8Engine","----initializing----");

    return 0;
}

JSRuntime* JSRuntime::GetJSRuntime() {
    return JSRuntime::instance;
}

jobject JSRuntime::GetJavaJSRuntime() {
    return JSRuntime::GetJSRuntime()->j_js_runtime;
}





