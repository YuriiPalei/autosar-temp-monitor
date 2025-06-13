#include "../include/temperature_monitor.hpp"

TemperatureMonitor::TemperatureMonitor(double threshold)
    : threshold(threshold), currentTemperature(0.0) {}

void TemperatureMonitor::update(double newTemperature) {
  currentTemperature = newTemperature;
}

double TemperatureMonitor::getCurrentTemperature() const {
  return currentTemperature;
}

bool TemperatureMonitor::isOverheating() const {
  return currentTemperature > threshold;
}
