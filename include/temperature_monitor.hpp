#ifndef TEMPERATURE_MONITOR_HPP
#define TEMPERATURE_MONITOR_HPP

class TemperatureMonitor {
public:
    TemperatureMonitor(double threshold);

    void update(double newTemperature);

    bool isOverheating() const;

    double getCurrentTemperature() const;

private:
    double threshold_;
    double currentTemperature_;
    bool overheating_;
};

#endif  // TEMPERATURE_MONITOR_HPP
