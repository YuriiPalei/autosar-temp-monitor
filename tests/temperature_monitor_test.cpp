#include <gtest/gtest.h>
#include "temperature_monitor.hpp"

TEST(TemperatureMonitorTest, InitialStateIsNotOverheating) {
    TemperatureMonitor monitor(75.0);
    EXPECT_FALSE(monitor.isOverheating());
    EXPECT_DOUBLE_EQ(monitor.getCurrentTemperature(), 0.0);
}

TEST(TemperatureMonitorTest, NormalTemperature) {
    TemperatureMonitor monitor(75.0);
    monitor.update(60.0);
    EXPECT_FALSE(monitor.isOverheating());
    EXPECT_DOUBLE_EQ(monitor.getCurrentTemperature(), 60.0);
}

TEST(TemperatureMonitorTest, OverheatingDetected) {
    TemperatureMonitor monitor(75.0);
    monitor.update(80.0);
    EXPECT_TRUE(monitor.isOverheating());
    EXPECT_DOUBLE_EQ(monitor.getCurrentTemperature(), 80.0);
}

TEST(TemperatureMonitorTest, BorderlineTemperature) {
    TemperatureMonitor monitor(75.0);
    monitor.update(75.0);
    EXPECT_FALSE(monitor.isOverheating());
    EXPECT_DOUBLE_EQ(monitor.getCurrentTemperature(), 75.0);
}
