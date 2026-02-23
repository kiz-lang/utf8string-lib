cmake_minimum_required(VERSION 3.14)
project(utf8_test)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 重点：把你的模块文件加进来
add_executable(utf8_test
  test.cpp
  core.cppm
)

target_link_libraries(utf8_test
  PRIVATE
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(utf8_test)