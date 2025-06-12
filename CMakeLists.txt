set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(TemperatureMonitor ${SOURCES})

add_subdirectory(tests)