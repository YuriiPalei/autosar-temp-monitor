#ifndef TEMPERATURE_MONITOR_HPP
#define TEMPERATURE_MONITOR_HPP

#include "autosar_adaptive.hpp"
#include "autosar_classic.hpp"

class TemperatureMonitor {
 public:
  explicit TemperatureMonitor(double threshold = 75.0);

  void update(double temperature);
  double getCurrentTemperature() const;
  bool isOverheating() const;

 private:
  double currentTemperature;
  double overheatThreshold;
  bool overheating;
};

#endif  // TEMPERATURE_MONITOR_HPP