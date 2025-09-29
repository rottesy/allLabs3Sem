#ifndef CONST_HPP
#define CONST_HPP

#include <string>

constexpr double CAR_WEIGHT_FACTOR = 500.0;
constexpr double BICYCLE_WEIGHT_FACTOR = 50.0;
constexpr double CARRIAGE_HORSE_FACTOR = 1.0;
constexpr double CARRIAGE_PASSENGER_DISCOUNT = 0.8;
constexpr double WEIGHT_DIVISOR = 100.0;
inline const std::string TRANSPORT_REG_NUMBER = "DEFAULT";

inline constexpr const int MAX_INT = 2147483647;
inline constexpr const int MIN_INT = -2147483648;

inline constexpr const double CAR_SPEED_IN_KM = 60;
inline constexpr const double CAR_COST_PER_KM = 1;
inline constexpr const double CAR_LOAD_CAP = 50;
inline constexpr const int CAR_MAX_PASS = 5;
inline const std::string CAR_REG_NUMBER = "CAR";

inline constexpr const double CARRIAGE_SPEED_IN_KM = 10;
inline constexpr const double CARRIAGE_COST_PER_KM = 0.5;
inline constexpr const double CARRIAGE_LOAD_CAP = 30;
inline constexpr const int NUMBER_OF_HORSES = 2;
inline const std::string CARRIAGE_REG_NUMBER = "CARRIAGE";

inline constexpr const double BICYCLE_SPEED_IN_KM = 20;
inline constexpr const double BICYCLE_COST_PER_KM = 0.05;
inline constexpr const double BICYCLE_LOAD_CAP = 5;
inline const std::string BICYCLE_REG_NUMBER = "BICYCLE";


#endif