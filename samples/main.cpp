#include "logDecorator.hpp"
#include <iostream>
#include <string>

// 示例目标函数声明
void say_hello(const std::string& name);

// 使用宏将日志装饰器应用到目标函数
ANNOTATE_DECORATOR("INFO", say_hello)(const std::string& name) {
    std::cout << "Hello, " << name << "!\n";
}

int main() {
    // 方式 1：使用宏定义的方式调用装饰后的函数
    say_hello_decorated("Alice");

    // ----------------------------

    // 方式 2：使用手动装饰的方式
    LoggingDecorator<std::function<void(const std::string&)>> logging_decorator(say_hello, "DEBUG");
    auto decorated_say_hello = logging_decorator.with_logging();

    // 调用手动装饰后的函数
    decorated_say_hello("Bob");

    return 0;
}
