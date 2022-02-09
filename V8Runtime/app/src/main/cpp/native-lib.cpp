#include <jni.h>
#include <string>
#include "v8.h"
#include "Utils.h"
#include "JSRuntimeException.h"
#include "JSRuntime.h"
#include "ValueConverter.h"

using namespace std;
//using namespace v8;



// JNI接口加载时调用，Application级别的生命周期
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {



    return 0x00010006;
}



// 初始化JS运行时
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_v8runtime_JSRuntime_initializeCppJSRuntime(JNIEnv *env, jclass clazz,jstring path,jstring flags) {

    ValueConverter::InitEnv(env);

    ::Utils::loge("ValueConvert Test", ValueConverter::J2CString(path).c_str());

    return 1;
}