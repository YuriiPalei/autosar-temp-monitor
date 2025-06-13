#include <gtest/gtest.h>

#include "../include/temperature_monitor.hpp"

TEST(TemperatureMonitorTest, InitialState) {
  TemperatureMonitor monitor(75.0);
  EXPECT_EQ(monitor.getCurrentTemperature(), 0.0);
}

TEST(TemperatureMonitorTest, NormalTemperatureUpdate) {
  TemperatureMonitor monitor(75.0);
  monitor.update(60.0);
  EXPECT_EQ(monitor.getCurrentTemperature(), 60.0);
}

TEST(TemperatureMonitorTest, OverheatTriggersCooling) {
  TemperatureMonitor monitor(75.0);
  monitor.update(80.0);
  EXPECT_EQ(monitor.getCurrentTemperature(), 80.0);
}