# General Decorator Template (通用装饰器模板)

## 项目介绍

This project provides a **generic decorator template** that allows users to easily apply pre- and post-actions to any function. The template supports logging, timing, and other customizable actions, making it flexible for various use cases.

该项目提供了一个 **通用装饰器模板**，允许用户轻松地为任何函数应用前置和后置操作。该模板支持日志记录、计时以及其他可自定义的操作，适用于多种场景。

最初的灵感来源于**python** 的装饰器，并结合C++的语言特性，支持动态装饰函数。你也可以通过宏定义来实现静态的装饰。

## 功能

- **Flexible Function Decoration:** Apply pre- and post-actions to any function.
- **Logging Support:** Built-in support for logging function entry, exit, and execution times.
- **Customizable:** Add any custom pre/post actions like logging, timing, etc.
- **Easy to Use:** Simple interface for function decoration without modifying function definitions.
- **Language Switching:** Supports both English and Chinese for easy use and documentation.

- **灵活的函数装饰:** 为任何函数应用前置和后置操作。
- **日志记录支持:** 内置支持记录函数的进入、退出和执行时间。
- **可定制:** 可以添加任何自定义的前置/后置操作，如日志记录、计时等。
- **易于使用:** 简单的界面可以装饰函数，而无需修改函数定义。
- **语言切换:** 支持中英双语，方便使用和文档查看。

## 前提条件

- A C++ compiler that supports C++17 or later (e.g., GCC, Clang, MSVC).
- C++ standard library (e.g., `iostream`, `unordered_map`, `functional`, `chrono`).

- 支持 C++17 或更高版本的编译器（如 GCC、Clang、MSVC）。
- C++ 标准库（如 `iostream`、`unordered_map`、`functional`、`chrono` 等）。

## 使用方法

### 1. 定义装饰器

You can define a decorator class that accepts pre- and post-function actions (like logging or timing) and applies them when the function is called.

你可以定义一个装饰器类，它接受前置和后置操作（如日志记录或计时），并在函数调用时应用这些操作。

### 2. 示例用法

In the following example, we use the Logger to log function calls with pre- and post-actions, such as logging entry/exit and return values.

在下面的示例中，我们使用 Logger 来记录函数调用的前置和后置操作，如日志记录函数的进入/退出和返回值。

### 3. 输出

The output will display logs with the function name, parameters, return value, and execution time.

输出将显示带有函数名、参数、返回值和执行时间的日志。

## 关键类和函数

- **Logger Class:** The main class responsible for applying the pre- and post-actions.
- **LogType Enum:** Defines different log types (INFO, DEBUG, TIMING).
- **add_pre_action:** Adds a pre-function action.
- **add_post_action:** Adds a post-function action.
- **log_function:** Logs a function call, including parameters, return value, and execution time.

- **Logger 类:** 主要负责应用前置和后置操作的类。
- **LogType 枚举:** 定义不同的日志类型（INFO、DEBUG、TIMING）。
- **add_pre_action:** 添加前置操作。
- **add_post_action:** 添加后置操作。
- **log_function:** 记录函数调用，包括参数、返回值和执行时间。

## 贡献

If you have any suggestions or improvements, feel free to open issues or submit pull requests.

如果你有任何建议或改进，欢迎提出问题或提交拉取请求。

## 许可证

This project is licensed under the MIT License - see the LICENSE file for details.

本项目采用 MIT 许可证 - 详细信息请参见 LICENSE 文件。

## 致谢

This project is built using the C++ Standard Library (iostream, unordered_map, chrono, etc.).

Inspired by the need for a flexible and customizable function decoration system.

本项目使用 C++ 标准库（utility、functional、type_traits 等）构建。

灵感来源于为函数装饰提供灵活且可定制的系统的需求。

### 语言切换说明

- **手动切换**：用户可以根据自己的偏好选择阅读英文部分或中文部分。
- **使用翻译工具**：用户可以使用 GitHub 的内置翻译功能或其他在线翻译工具进行语言切换。

希望这个 README.md 文件能帮助你更好地理解和使用本项目。如果有任何问题或建议，请随时联系。
