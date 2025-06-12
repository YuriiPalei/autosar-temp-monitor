#ifndef TEMPERATURE_MONITOR_HPP
#define TEMPERATURE_MONITOR_HPP

class TemperatureMonitor {
public:
    explicit TemperatureMonitor(double threshold);

    void update(double newTemperature);

    double getCurrentTemperature() const;

    bool isOverheating() const;

private:
    double currentTemperature;
    double threshold;
};

#endif // TEMPERATURE_MONITOR_HPP