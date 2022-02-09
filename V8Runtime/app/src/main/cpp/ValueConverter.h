//
// Created by 谢荣基 on 2022/1/30.
//

#ifndef V8RUNTIME_VALUECONVERTER_H
#define V8RUNTIME_VALUECONVERTER_H
#include <string>
#include "jni.h"
#include "JSRuntimeException.h"

class ValueConverter {

public:

    static void InitEnv(JNIEnv * env);
    static std::string J2CString(jstring jString);
    static jstring C2JString(std::string cString);

private:
    static JNIEnv * env;

};


#endif //V8RUNTIME_VALUECONVERTER_H
