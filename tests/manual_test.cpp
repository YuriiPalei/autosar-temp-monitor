#include <iostream>
#include "../include/temperature_monitor.hpp"

void test_initial_state() {
    TemperatureMonitor monitor(75.0);
    if (!monitor.isOverheating() && monitor.getCurrentTemperature() == 0.0) {
        std::cout << "test_initial_state passed\n";
    } else {
        std::cout << "test_initial_state FAILED\n";
    }
}

void test_overheating() {
    TemperatureMonitor monitor(75.0);
    monitor.update(80.0);
    if (monitor.isOverheating()) {
        std::cout << "test_overheating passed\n";
    } else {
        std::cout << "test_overheating FAILED\n";
    }
}

void test_update() {
    TemperatureMonitor monitor(75.0);
    monitor.update(60.0);
    if (monitor.getCurrentTemperature() == 60.0) {
        std::cout << "test_update passed\n";
    } else {
        std::cout << "test_update FAILED\n";
    }
}

int main() {
    test_initial_state();
    test_overheating();
    test_update();
    return 0;
}
