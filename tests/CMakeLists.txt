cmake_minimum_required(VERSION 3.15)

enable_testing()

# Підключаємо FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

# Завантажуємо GTest
FetchContent_MakeAvailable(googletest)

add_executable(runTests
        test_temperature_monitor.cpp
        ../src/temperature_monitor.cpp
        ../src/autosar_adaptive.cpp
        ../src/autosar_classic.cpp
)

target_include_directories(runTests PUBLIC
        ../include
)

target_link_libraries(runTests gtest_main)

include(GoogleTest)
gtest_discover_tests(runTests)