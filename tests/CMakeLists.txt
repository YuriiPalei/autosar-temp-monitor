enable_testing()
include_directories(../include)

add_executable(manualTests manual_test.cpp ../src/temperature_monitor.cpp)