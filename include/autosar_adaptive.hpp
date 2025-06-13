#ifndef AUTOSAR_ADAPTIVE_HPP
#define AUTOSAR_ADAPTIVE_HPP

namespace AutosarAdaptive {
void logTemperature(double temperature);
void publishOverheatEvent(double temperature);
}  // namespace AutosarAdaptive

#endif  // AUTOSAR_ADAPTIVE_HPP