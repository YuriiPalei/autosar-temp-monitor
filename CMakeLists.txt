cmake_minimum_required(VERSION 3.10)
project(TemperatureMonitor)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(TemperatureMonitor ${SOURCES})

enable_testing()
add_subdirectory(tests)