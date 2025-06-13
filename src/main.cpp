#include <iostream>

#include "temperature_monitor.hpp"

int main() {
  TemperatureMonitor monitor(75.0);

  double inputTemp;
  std::cout << "Enter temperature value: ";
  std::cin >> inputTemp;

  monitor.update(inputTemp);

  std::cout << "Current: " << monitor.getCurrentTemperature() << "°C\n";
  if (monitor.isOverheating()) {
    std::cout << "Warning: Overheating detected!\n";
  } else {
    std::cout << "Temperature is normal.\n";
  }

  return 0;
}
