# JSON文件读写操作示例 (MSVC)

本项目演示如何使用MSVC（Microsoft Visual C++）进行JSON文件的读写操作。

## 依赖库

本项目使用 [nlohmann/json](https://github.com/nlohmann/json) 库，这是一个流行的C++ JSON库，支持header-only使用。

## 编译说明

### 使用Visual Studio (MSVC)

1. 打开Visual Studio
2. 选择"文件" -> "打开" -> "CMake..."
3. 选择本目录下的CMakeLists.txt文件
4. Visual Studio会自动配置项目并下载所需的依赖库
5. 按F5编译并运行项目

### 使用命令行 (MSVC)

1. 打开"开发者命令提示符"或"开发者PowerShell"
2. 切换到项目目录
3. 运行以下命令：

```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"  # 或其他可用的Visual Studio版本
cmake --build .
```

或者使用MSBuild：

```cmd
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019"
MSBuild json_io_example.sln
```

## 功能说明

程序会执行以下操作：

1. 创建一个JSON对象，包含字符串、数字、布尔值、数组和嵌套对象
2. 将JSON对象写入"data.json"文件
3. 从"data.json"文件读取JSON数据
4. 显示读取的数据并输出特定字段

## 输出示例

程序运行后将创建data.json文件并输出读取的数据。