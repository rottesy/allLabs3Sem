#pragma once

#include <array>
#include <iostream>

inline const int MONTH_COUNT = 12;
inline const std::array<int, MONTH_COUNT> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline const int LEAP_FEBRUARY_DAYS = 29;
inline const int FORMAT_DATE_LEN = 8;

inline const std::string FILE_WITH_PRODUCTS = "products.txt";

