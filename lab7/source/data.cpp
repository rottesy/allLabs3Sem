#include "../include/data.hpp"
#include <iomanip>
#include <iostream>

#include "../include/consts.hpp"
#include "../include/utils.hpp"

Date::Date(int inputDay, int inputMonth, int inputYear) : day(inputDay), month(inputMonth), year(inputYear) {}

bool Date::isLeapYear() const { return (year % 4 == 0); }

int Date::getDaysInMonth() const
{
    if (month == 2 && isLeapYear())
    {
        return kLeapFebruaryDays;
    }

    return kDaysInMonth[month - 1];
}

void Date::showDateFormatException(const std::string &date, const std::exception &exc)
{
    std::cout << kRedColor << "\nIncorrect date format: " << exc.what() << " | input: " << date << kWhiteColor << "\n";
}

void Date::parse(const std::string &date)
{
    try
    {
        if (date.length() != kFormatDateLen)
        {
            throw std::invalid_argument("expected format dd.mm.yy (8 characters)");
        }

        if (date[2] != '.' || date[5] != '.')
        {
            throw std::invalid_argument("separator must be a dot at positions 3 and 6");
        }

        if (!isDigits(date, 0, 2) || !isDigits(date, 3, 2) || !isDigits(date, 6, 2))
        {
            throw std::invalid_argument("day, month and year must contain only digits");
        }

        int tmpDay = std::stoi(date.substr(0, 2));
        int tmpMonth = std::stoi(date.substr(3, 2));
        int tmpYear = std::stoi(date.substr(6, 2));

        if (tmpMonth < 1 || tmpMonth > kMonthCount)
        {
            throw std::invalid_argument("month out of range (01..12)");
        }

        Date tmp(tmpDay, tmpMonth, tmpYear);

        if (tmpDay < 1 || tmpDay > tmp.getDaysInMonth())
        {
            throw std::invalid_argument("day out of range for this month");
        }

        *this = tmp;
    }
    catch (const std::invalid_argument &exc)
    {
        showDateFormatException(date, exc);
    }
    catch (const std::out_of_range &exc)
    {
        showDateFormatException(date, exc);
    }
}

void Date::input()
{
    std::string inputDate;

    while (true)
    {
        inputDate = getValue<std::string>("\nPlease enter the date(DD.MM.YY): ");

        parse(inputDate);
        if (!isEmpty())
        {
            return;
        }
    }
}

bool Date::isEmpty() const { return (day == 0 || month == 0 || year == 0); }