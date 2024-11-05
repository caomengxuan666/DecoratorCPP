#ifndef LOG_DECORATOR_HPP
#define LOG_DECORATOR_HPP

#include "decorator.hpp"
#include <iostream>
#include <string>

// 日志装饰器类，继承通用装饰器
template <typename Func>
class LoggingDecorator : public Decorator<Func> {
public:
    LoggingDecorator(Func func, std::string level)
        : Decorator<Func>(std::move(func)), level_(std::move(level)) {}

    auto with_logging() const {
        auto pre_action = [level = level_] { std::cout << "[" << level << "] Before function call\n"; };
        auto post_action = [level = level_] { std::cout << "[" << level << "] After function call\n"; };
        return this->with_actions(pre_action, post_action);
    }

private:
    std::string level_;
};

// 宏定义，用于装饰函数
#define ANNOTATE_DECORATOR(level, func) \
    auto func##_decorated = LoggingDecorator(std::function<void(const std::string&)>(func), level).with_logging(); \
    void func

#endif // LOG_DECORATOR_HPP
