#include "../include/autosar_adaptive.hpp"

#include <iostream>

namespace AutosarAdaptive {
void logTemperature(double temperature) {
  std::cout << "[Adaptive] Logging temperature: " << temperature << "°C"
            << std::endl;
}

void publishOverheatEvent(double temperature) {
  std::cout << "[Adaptive] Overheat detected! Temperature: " << temperature
            << "°C" << std::endl;
}
}  // namespace AutosarAdaptive