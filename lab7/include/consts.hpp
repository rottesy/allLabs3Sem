#pragma once

#include <array>
#include <iostream>

inline const int kMonthCount = 12;
inline const std::array<int, kMonthCount> kDaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline const int kLeapFebruaryDays = 29;
inline const int kFormatDateLen = 8;

inline const std::string kFileWithProducts = "products.txt";

inline const int kIndentWidth = 16;