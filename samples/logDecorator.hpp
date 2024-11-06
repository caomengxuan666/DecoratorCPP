#include <iostream>
#include <chrono>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>

// 获取当前日期和时间
std::string current_datetime() {
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Logger 类
class Logger {
public:
    // 添加预定义的日志类型
    enum class LogType { INFO, DEBUG, TIMING };

    // 添加前置操作
    void add_pre_action(LogType type, std::function<void()> action) {
        pre_actions_[type].push_back(action);
    }

    // 添加后置操作
    void add_post_action(LogType type, std::function<void()> action) {
        post_actions_[type].push_back(action);
    }

    // 执行前置操作
    void execute_pre_actions(LogType type) const {
        if (pre_actions_.find(type) != pre_actions_.end()) {
            for (const auto& action : pre_actions_.at(type)) {
                action();
            }
        }
    }

    // 执行后置操作
    void execute_post_actions(LogType type) const {
        if (post_actions_.find(type) != post_actions_.end()) {
            for (const auto& action : post_actions_.at(type)) {
                action();
            }
        }
    }

    // 清除指定类型的前置和后置操作
    void clear_actions(LogType type) {
        pre_actions_.erase(type);
        post_actions_.erase(type);
    }

    // 使用日志装饰函数
    template <typename Func, typename... Args>
    auto log_function(LogType type, const char* func_name, int line_number, Func&& func, Args&&... args) const {
        execute_pre_actions(type);

        std::cout << "[" << current_datetime() << "] Function: " << func_name << " at line " << line_number << "\n";

        // 打印参数
        std::cout << "Arguments: ";
        (std::cout << ... << (std::to_string(args) + " "));
        std::cout << std::endl;

        if constexpr (std::is_void_v<std::invoke_result_t<Func, Args...>>) {
            std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
            execute_post_actions(type);
        } else {
            auto result = std::invoke(std::forward<Func>(func), std::forward<Args>(args)...);
            std::cout << "Return value: " << result << std::endl;
            execute_post_actions(type);
            return result;
        }
    }

private:
    std::unordered_map<LogType, std::vector<std::function<void()>>> pre_actions_;
    std::unordered_map<LogType, std::vector<std::function<void()>>> post_actions_;
};

// 定义一些预设的日志操作
std::function<void()> make_log_pre_action(const std::string& level) {
    return [level] { std::cout << "[" << level << "] Before function call\n"; };
}

std::function<void()> make_log_post_action(const std::string& level) {
    return [level] { std::cout << "[" << level << "] After function call\n"; };
}

// 示例：时间测量的前置操作
std::function<void()> make_timing_pre_action() {
    return [] { std::cout << "Timing start...\n"; };
}

// 示例：时间测量的后置操作
std::function<void()> make_timing_post_action() {
    return [] { std::cout << "Timing end...\n"; };
}

