#include "decorator.hpp"
#include "logDecorator.hpp"

// 示例函数

void say_hello(const std::string &name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}


int add_numbers(int a, int b) {
    return a + b;
}


int main() {

    //一个自定义函数装饰器实现
    // 创建通用装饰器实例并应用日志操作
    Decorator decorator(say_hello);

    auto decorated_say_hello_with_logging = decorator.with_actions(
            make_log_pre_action("INFO"),
            make_log_post_action("INFO"));

    // 调用带日志功能的装饰后的函数
    decorated_say_hello_with_logging("Alice");

    // 创建通用装饰器实例并应用时间测量操作
    auto decorated_say_hello_with_timing = decorator.with_actions(
            make_timing_pre_action(),
            make_timing_post_action());

    // 调用带时间测量功能的装饰后的函数
    decorated_say_hello_with_timing("Bob");

    std::cout << "--------\n";


    //具体的一个日志类实现
    Logger logger;

    // 添加一些预设的操作
    logger.add_pre_action(Logger::LogType::INFO, make_log_pre_action("INFO"));
    logger.add_post_action(Logger::LogType::INFO, make_log_post_action("INFO"));
    logger.add_pre_action(Logger::LogType::TIMING, make_timing_pre_action());
    logger.add_post_action(Logger::LogType::TIMING, make_timing_post_action());

    // 使用日志装饰 add_numbers 函数
    int result = logger.log_function(Logger::LogType::INFO, __FUNCTION__, __LINE__, add_numbers, 5, 3);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
