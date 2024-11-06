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
        return [func = func_, pre_action = std::move(pre_action), post_action = std::move(post_action)](auto&&... args) mutable {
            // 调用前置操作
            pre_action();

            // 调用主函数
            if constexpr (std::is_void_v<std::invoke_result_t<Func, decltype(args)...>>) {
                func(std::forward<decltype(args)>(args)...);
                // 调用后置操作
                post_action();
            } else {
                auto result = func(std::forward<decltype(args)>(args)...);
                // 调用后置操作
                post_action();
                return result;
            }
        };
    }

    Func get_decorated_func() const {
        return func_;
    }

private:
    Func func_;
};

#endif // DECORATOR_HPP
