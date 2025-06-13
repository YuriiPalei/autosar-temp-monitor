enable_testing()
include_directories(../include)

add_executable(manualTests manual_test.cpp ../src/temperature_monitor.cpp ../src/autosar_adaptive.cpp ../src/autosar_classic.cpp)