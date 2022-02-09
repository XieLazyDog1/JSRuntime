//
// Created by 谢荣基 on 2022/1/30.
//

#include "ValueConverter.h"

JNIEnv * ValueConverter::env = nullptr;

std::string ValueConverter::J2CString(jstring jString) {
    if(env == nullptr)
        throw JSRuntimeException("JNIEnv not initialized");
    return std::string(env->GetStringUTFChars(jString,0));
}

jstring ValueConverter::C2JString(std::string cString) {
    if(env == nullptr)
        throw JSRuntimeException("JNIEnv not initialized");
    return env->NewStringUTF(cString.c_str());
}

void ValueConverter::InitEnv(JNIEnv * j_env) {
    env = j_env;
}

