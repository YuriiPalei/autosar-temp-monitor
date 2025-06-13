#include "../include/temperature_monitor.hpp"

TemperatureMonitor::TemperatureMonitor(double threshold)
    : currentTemperature(0.0),
      overheatThreshold(threshold),
      overheating(false) {}

void TemperatureMonitor::update(double temperature) {
  currentTemperature = temperature;
  AutosarAdaptive::logTemperature(temperature);

  if (temperature > overheatThreshold) {
    if (!overheating) {
      overheating = true;
      AutosarAdaptive::publishOverheatEvent(temperature);
      AutosarClassic::triggerCoolingSystem();
    }
  } else {
    overheating = false;
  }
}

double TemperatureMonitor::getCurrentTemperature() const {
  return currentTemperature;
}

bool TemperatureMonitor::isOverheating() const { return overheating; }