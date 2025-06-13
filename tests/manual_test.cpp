#include <iostream>

#include "../include/temperature_monitor.hpp"

void test_initial_state() {
  TemperatureMonitor monitor;
  if (monitor.getCurrentTemperature() != 0.0 || monitor.isOverheating()) {
    std::cerr << "test_initial_state FAILED" << std::endl;
  } else {
    std::cout << "test_initial_state passed" << std::endl;
  }
}

void test_update() {
  TemperatureMonitor monitor;
  monitor.update(60.0);
  if (monitor.getCurrentTemperature() != 60.0 || monitor.isOverheating()) {
    std::cerr << "test_update FAILED" << std::endl;
  } else {
    std::cout << "test_update passed" << std::endl;
  }
}

void test_overheating() {
  TemperatureMonitor monitor;
  monitor.update(80.0);
  if (!monitor.isOverheating()) {
    std::cerr << "test_overheating FAILED" << std::endl;
  } else {
    std::cout << "test_overheating passed" << std::endl;
  }
}

int main() {
  test_initial_state();
  test_update();
  test_overheating();
  return 0;
}