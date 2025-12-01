cmake_minimum_required(VERSION 3.10)
project(json_io_example)

set(CMAKE_CXX_STANDARD 17)

# 下载nlohmann/json库
include(FetchContent)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(nlohmann_json)

# 添加可执行文件
add_executable(json_io_example main.cpp)

# 链接nlohmann/json库
target_link_libraries(json_io_example nlohmann_json::nlohmann_json)