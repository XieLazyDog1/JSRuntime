//
// Created by 谢荣基 on 2022/1/30.
//

#include "JSRuntimeException.h"

JSRuntimeException::JSRuntimeException(const std::string& message) {
    this->message = message;
}

std::string JSRuntimeException::getMessage(void) {
    return this->message;
}

void JSRuntimeException::printToLogcat(const std::string tag) {
    std::string eTag = "JSRuntimeException: ";
    eTag.append(tag);
    Utils::loge(tag.c_str(),message.c_str());
}

void JSRuntimeException::printToLogcat() {
    Utils::loge("JSRuntimeException",message.c_str());
}
