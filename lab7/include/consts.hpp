#pragma once

#include <array>
#include <iostream>

inline const std::string kWhiteColor = "\o{33}[0m";
inline const std::string kRedColor = "\o{33}[31m";
inline const std::string kGreenColor = "\o{33}[32m";

inline const int kMonthCount = 12;
inline const std::array<int, kMonthCount> kDaysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
inline const int kLeapFebruaryDays = 29;
inline const int kFormatDateLen = 8;

inline const int kFormatTimeLen = 8;
inline const int kHoursCount = 23;
inline const int kMinutesCount = 59;
inline const int kSecondsCount = 59;

inline const std::string kFileWithProducts = "products.txt";

inline const int kIndentWidth = 16;