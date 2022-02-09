//
// Created by 谢荣基 on 2022/1/30.
//

#ifndef V8RUNTIME_JSRUNTIMEEXCEPTION_H
#define V8RUNTIME_JSRUNTIMEEXCEPTION_H
#include <string>
#include "Utils.h"

class JSRuntimeException {

public:
    JSRuntimeException(const std::string& message);

    std::string getMessage(void);

    void printToLogcat(const std::string tag);

    void printToLogcat();

private:
    std::string message;
};


#endif //V8RUNTIME_JSRUNTIMEEXCEPTION_H
