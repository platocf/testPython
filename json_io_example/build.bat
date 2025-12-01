@echo off
echo 正在使用MSVC编译JSON IO示例项目...

REM 检查是否在开发者命令提示符中
if not defined VCINSTALLDIR (
    echo 错误: 请在Visual Studio开发者命令提示符中运行此脚本
    pause
    exit /b 1
)

REM 创建构建目录
if not exist build mkdir build
cd build

REM 配置项目
cmake .. -G "Visual Studio 16 2019" || cmake .. -G "Visual Studio 15 2017" || cmake .. -G "Visual Studio 17 2022"

if errorlevel 1 (
    echo CMake配置失败
    cd ..
    pause
    exit /b 1
)

REM 编译项目
msbuild json_io_example.sln /p:Configuration=Release

if errorlevel 1 (
    echo 编译失败
    cd ..
    pause
    exit /b 1
)

echo 编译成功！
echo 运行程序: build\Release\json_io_example.exe
cd ..

pause