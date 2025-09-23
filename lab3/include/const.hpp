#ifndef CONST_HPP
#define CONST_HPP

constexpr double CAR_WEIGHT_FACTOR = 500.0;
constexpr double BICYCLE_WEIGHT_FACTOR = 50.0;
constexpr double CARRIAGE_HORSE_FACTOR = 1.0;
constexpr double CARRIAGE_PASSENGER_DISCOUNT = 0.8;
constexpr double WEIGHT_DIVISOR = 100.0;

inline constexpr const int kMaxInt = 2147483647;
inline constexpr const int kMinInt = -2147483648;

inline constexpr const double kCarSpeedInKm = 60;
inline constexpr const double kCarCostPerKm = 1;
inline constexpr const double kCarLoadCap = 50;
inline constexpr const int kCarMaxPass = 5;

inline constexpr const double kCarriageSpeedInKm = 10;
inline constexpr const double kCarriageCostPerKm = 0.5;
inline constexpr const double kCarriageLoadCap = 30;
inline constexpr const int kNumberOfHorses = 2;

inline constexpr const double kBicycleSpeedInKm = 20;
inline constexpr const double kBicycleCostPerKm = 0.05;
inline constexpr const double kBicycleLoadCap = 5;

#endif