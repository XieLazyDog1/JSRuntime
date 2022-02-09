//
// Created by 谢荣基 on 2022/1/29.
//

#include "Utils.h"

std::string APP_ROOT_DIR_PATH = ""; // 应用私有存储根目录
std::string V8_STARTUP_FLAGS = "";  // V8引擎启动参数


timespec Utils::recordTime{};

void Utils::logv(char const* tag,char const* msg){
    __android_log_write(ANDROID_LOG_VERBOSE,tag,msg);
}
void Utils::logi(char const* tag,char const* msg){
    __android_log_write(ANDROID_LOG_INFO,tag,msg);
}
void Utils::logd(char const* tag,char const* msg){
    __android_log_write(ANDROID_LOG_DEBUG,tag,msg);
}
void Utils::logw(char const* tag,char const* msg){
    __android_log_write(ANDROID_LOG_WARN,tag,msg);
}
void Utils::loge(char const* tag,char const* msg){
    __android_log_write(ANDROID_LOG_ERROR,tag,msg);
}

void Utils::startTimeRecord() {
    clock_gettime(CLOCK_REALTIME,&recordTime);
}

long Utils::stopTimeRecordForNs() {
    timespec now{};
    clock_gettime(CLOCK_REALTIME,&now);
    return (now.tv_sec - recordTime.tv_sec) * 1000000000L + ( now.tv_nsec - recordTime.tv_nsec );
}

long Utils::stopTimeRecordForUs() {
    timespec now{};
    clock_gettime(CLOCK_REALTIME,&now);
    return (now.tv_sec - recordTime.tv_sec) * 1000000 + ( now.tv_nsec - recordTime.tv_nsec )/1000;
}

long Utils::stopTimeRecordForMs() {
    timespec now{};
    clock_gettime(CLOCK_REALTIME,&now);
    return (now.tv_sec - recordTime.tv_sec) * 1000 + ( now.tv_nsec - recordTime.tv_nsec )/1000000;
}


