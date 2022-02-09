//
// Created by 谢荣基 on 2022/1/29.
//

#ifndef V8RUNTIME_UTILS_H
#define V8RUNTIME_UTILS_H

#include <android/log.h>
#include <ctime>
#include <string>
#include <jni.h>
#include "ValueConverter.h"

class Utils {
public:

    static std::string APP_ROOT_DIR_PATH;
    static std::string V8_STARTUP_FLAGS;


    static void logv(char const* tag, char const* msg);
    static void logi(char const* tag, char const* msg);
    static void logd(char const* tag, char const* msg);
    static void logw(char const* tag,char const* msg);
    static void loge(char const* tag, char const* msg);


    static void startTimeRecord();
    static long stopTimeRecordForNs();
    static long stopTimeRecordForUs();
    static long stopTimeRecordForMs();


private:
    static struct timespec recordTime;

};


#endif //V8RUNTIME_UTILS_H
