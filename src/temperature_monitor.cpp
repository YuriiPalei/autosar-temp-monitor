#include "temperature_monitor.hpp"

TemperatureMonitor::TemperatureMonitor(double threshold)
    : threshold_(threshold), currentTemperature_(0.0), overheating_(false) {
}

void TemperatureMonitor::update(double newTemperature) {
    currentTemperature_ = newTemperature;
    overheating_ = newTemperature > threshold_;
}

bool TemperatureMonitor::isOverheating() const {
    return overheating_;
}

double TemperatureMonitor::getCurrentTemperature() const {
    return currentTemperature_;
}
