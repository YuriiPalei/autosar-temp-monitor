#include <iostream>

#include "../include/temperature_monitor.hpp"

int main() {
  TemperatureMonitor monitor(75.0);

  monitor.update(60.0);
  monitor.update(80.0);
  monitor.update(70.0);

  std::cout << "Final Temperature: " << monitor.getCurrentTemperature() << "°C"
            << std::endl;
  std::cout << "Is Overheating: " << (monitor.isOverheating() ? "Yes" : "No")
            << std::endl;

  return 0;
}