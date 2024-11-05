#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <utility>
#include <functional>
#include <type_traits>

// 通用装饰器模板类
template <typename Func>
class Decorator {
public:
    explicit Decorator(Func func) : func_(std::move(func)) {}

    template <typename PreAction, typename PostAction>
    auto with_actions(PreAction pre_action, PostAction post_action) const {
        return [func = func_, pre_action, post_action](auto&&... args) {
            pre_action();  // 执行前置操作

            if constexpr (std::is_void_v<std::invoke_result_t<Func, decltype(args)...>>) {
                func(std::forward<decltype(args)>(args)...);
                post_action();  // 执行后置操作
            } else {
                auto result = func(std::forward<decltype(args)>(args)...);
                post_action();  // 执行后置操作
                return result;
            }
        };
    }

private:
    Func func_;
};

#endif // DECORATOR_HPP
