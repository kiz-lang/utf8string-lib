cmake_minimum_required(VERSION 3.14)
project(utf8_test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动下载 Google Test (通过 FetchContent)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# 对于 Windows，防止出现编译错误
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 构建测试可执行文件
add_executable(utf8_test test.cpp)

# 链接 gtest 库
target_link_libraries(utf8_test GTest::gtest_main)

# 自动发现测试用例
include(GoogleTest)
gtest_discover_tests(utf8_test)