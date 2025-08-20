//  This file is part of my personal string library "Date-Library"
// Originally developed to simplify coding tasks.
 //original repository: https://github.com/nalodagreat/Date-Library
#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "clsString.h" 
using namespace std;

class Date
{
private:
	short day;
	short month;
	short year;
public:
	Date()
	{
		time_t t = time(0);
		tm now = {};
		localtime_s(&now, &t);
		day = now.tm_mday;
		month = now.tm_mon + 1;
		year = now.tm_year + 1900;
	}

	Date(short day, short month, short year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	short getDay()
	{
		return day;
	}
	short getmonth()
	{
		return month;
	}
	short getyear()
	{
		return year;
	}
	void setDay(short day)
	{
		this->day = day;
	}
	void setmonth(short month)
	{
		this->month = month;
	}
	void setyear(short year)
	{
		this->year = year;
	}

private:
	static string concatinateDate(short day, short month, short year)
	{
		string concatinateDate = "", separator = "/";
		concatinateDate += to_string(day);
		concatinateDate += separator + to_string(month);
		return concatinateDate += separator + to_string(year);
	}
public:
	static string dateTostring(Date date)
	{
		return concatinateDate(date.day, date.month, date.year);
	}
	string dateTostring()
	{
		return dateTostring(*this);
	}
	struct systemDate
	{
		short day;
		short month;
		short year;
	};
	static systemDate getSystemDate()
	{
		systemDate systemDate;
		time_t t = time(0);
		tm now = {};
		localtime_s(&now, &t);
		systemDate.day = now.tm_mday;
		systemDate.month = now.tm_mon + 1;
		systemDate.year = now.tm_year + 1900;
		return systemDate;
	}
	static bool Isdate1Beforedate2(Date date1, Date date2)
	{
		return (date1.year < date2.year)
			? true
			: ((date1.year == date2.year)
				? (date1.month < date2.month
					? true
					: (date1.month == date2.month
						? date1.day < date2.day
						: false))
				: false);
	}
	bool IsDateBeforeDate2(Date date2)
	{
		//note: *this sends the current object :-)
		return  Isdate1Beforedate2(*this, date2);
	}
	static bool isLeapYear(short year)
	{
		// if year is divisible by 4 AND not divisible by 100// OR if year is divisible by 400// then it is a leap year 
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(year);
	}
	static short numberOfDaysInAYear(short year)
	{
		return  isLeapYear(year) ? 365 : 364;
	}
	short numberOfDaysInAYear()
	{
		return  numberOfDaysInAYear(year);
	}
	static short numberOfHoursInAYear(short year)
	{
		return numberOfDaysInAYear(year) * 24;
	}
	short numberOfHoursInAYear()
	{
		return numberOfHoursInAYear(year);
	}
	static short numberOfDaysInAMonth(short month, int year)
	{
		if (month < 1 || month>12)
			return  0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (month == 2) ? (isLeapYear(year) ? 29 : 28) : days[month - 1];
	}
	short numberOfDaysInAMonth()
	{
		return numberOfDaysInAMonth(month, year);
	}
	static Date DecreaseDateByOneYear(Date date)
	{
		date.year--;
		return date;
	}
	Date DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);
	}
	Date addDaysToDate(int daysToAdd)
	{
		Date result = *this;

		while (daysToAdd > 0)
		{
			short daysInMonth = numberOfDaysInAMonth(result.month, result.year);

			if (result.day + daysToAdd <= daysInMonth)
			{
				result.day += daysToAdd;
				break;
			}
			else
			{
				daysToAdd -= (daysInMonth - result.day + 1);
				result.day = 1;

				if (result.month == 12)
				{
					result.month = 1;
					result.year++;
				}
				else
				{
					result.month++;
				}
			}
		}

		return result;
	}
	bool isEndOfMonth()
	{
		return day == numberOfDaysInAMonth(month, year);
	}
	static string getSystemTime()
	{
		//getthetime in format: hour::minutes::seconds
		short hours, minutes, seconds;
		time_t t = time(0);
		tm now = {};
		localtime_s(&now, &t);
		hours = now.tm_hour;
		minutes = now.tm_min;
		seconds = now.tm_sec;
		return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
	}
	static string convertDateOfLoginstructToString(systemDate date, string seperator = "/")
	{
		string line = "";
		line += to_string(date.day) + seperator;
		line += to_string(date.month) + seperator;
		line += to_string(date.year);
		return line;
	}
	static systemDate convertStringToDateOfLoginstruct(string line, string seperator = "/")
	{
		systemDate date;
		vector<string> vData = clsString::Split(line, seperator);
		if (vData.size() == 3)
		{
			date.day = stoi(vData[0]);
			date.month = stoi(vData[1]);
			date.year = stoi(vData[2]);
		}
		return date;
	}
	static int yearsSinceDate(Date fromDate)
	{
		systemDate sys = getSystemDate();

		int years = sys.year - fromDate.getyear();

		if ((sys.month < fromDate.getmonth()) ||
			(sys.month == fromDate.getmonth() && sys.day < fromDate.getDay()))
		{
			years--;
		}

		return years;
	}
	static Date convertStringToDat(string line, string seperator = "-")
	{
		Date date;
		vector<string> vData = clsString::Split(line, seperator);
		if (vData.size() == 3)
		{
			date.setDay(stoi(vData[0]));
			date.setmonth(stoi(vData[1]));
			date.setyear(stoi(vData[2]));
		}
		return date;
	}
};