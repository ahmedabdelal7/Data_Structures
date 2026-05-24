
#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>//setw()
#include "clsString.h"

using namespace std;


class clsDate {
public:
	short _Day = 0;
	short _Month = 0;
	short _Year = 0;

	//Constructors
	clsDate() {
		time_t t = time(0); //local time

		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDate(string sDate) {

		vector<string> vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year) {

		_Day = Day;
		_Month = Month;
		_Year = Year;

	}

	clsDate(short YearDayes, short Year) {

		clsDate Date = ConvertTotalDaysToDate(YearDayes, Year);
		_Year = Date._Year;
		_Month = Date._Month;
		_Day = Date._Day;

	}


	//Day Properties 
	void SetDay(short Day) {
		this->_Day = Day;
	}
	short GetDay() {
		return this->_Day;
	}
	_declspec(property(get = GetDay, put = SetDay))short Day;

	//Month Properties 
	void SetMonth(short Month) {
		this->_Month = Month;
	}
	short GetMonth() {
		return this->_Month;
	}
	_declspec(property(get = GetMonth, put = SetMonth))short Month;

	//Year Properties 
	void SetYear(short Year) {
		this->_Year = Year;
	}
	short GetYear() {
		return this->_Year;
	}
	_declspec(property(get = GetYear, put = SetYear))short Year;


	//Date Methodes

	void Print() {
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate() {

		time_t t = time(0); //local time
		tm* now = localtime(&t);

		short Year, Month, Day;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);

	}

	static string GetSystemDateTimeString() {

		time_t t = time(0); //local time

		tm* now = localtime(&t);
		short Year, Month, Day, Hours, Min, Sec;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hours = now->tm_hour;
		Min = now->tm_min;
		Sec = now->tm_sec;


		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) +
			" - " + to_string(Hours) + ":" + to_string(Min) + ":" + to_string(Sec));

	}

	static bool IsValid(clsDate Date) {

		//if (this->Month > 12 || this->Month < 1)
		//	return false;
		//if (this->Day > 31 || this->Day < 1)
		//	return false;
		//if (this->Year < 1)
		//	return false;
		//if (this->Day > NumOfDaysInAMonth(this->Month, this->Year))
		//	return false;

		return (Date.Month <= 12 || Date.Month >= 1) ? ((Date.Day <= 31 || Date.Day >= 1) ? (Date.Year >= 1) ? (Date.Day <= NumOfDaysInAMonth(Date.Month, Date.Year)) ? true : false : false : false) : false;


	}

	bool IsValid() {
		return IsValid(*this);
	}

	static string DateToString(clsDate Date) {

		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

	}

	string DateToString() {
		return DateToString(*this);
	}

	static bool IsLeapYear(short year) {

		return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	}

	bool IsLeapYear() {
		return IsLeapYear(_Year);
	}

	static short NumOfDaysInAYear(short year) {
		return (IsLeapYear(year) ? 366 : 365);
	}

	short NumOfDaysInAYear() {
		return NumOfDaysInAYear(_Year);
	}

	static short NumOfHoursInAYear(short year) {
		return NumOfDaysInAYear(year) * 24;
	}

	short NumOfHoursInAYear() {
		return NumOfHoursInAYear(_Year);
	}

	static int NumOfMinutesInAYear(short year) {
		return NumOfHoursInAYear(year) * 60;
	}

	int NumOfMinutesInAYear() {
		return NumOfMinutesInAYear(_Year);
	}

	static int NumOfSecondsInAYear(short year) {
		return NumOfMinutesInAYear(year) * 60;
	}

	int NumOfSecondsInAYear() {
		return NumOfSecondsInAYear(_Year);
	}


	//bool IsLastMonthInYear() {

	//	return IsLastMonthInYear(_Month);
	//}
//
	static short NumOfDaysInAMonth(short Month, short year) {

		if (Month < 1 || Month > 12)
			return 0;

		short Arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


		return Month == 2 ? (IsLeapYear(year) ? 29 : 28) : Arr[Month - 1];
	}

	short NumOfDaysInAMonth() {
		return NumOfDaysInAMonth(_Month, _Year);

	}

	static short NumOfHoursInAMonth(short Month, short Year) {
		return NumOfDaysInAMonth(Month, Year) * 24;
	}

	short NumOfHoursInAMonth() {
		return NumOfHoursInAMonth(_Month, _Year);
	}

	static short NumOfMinutesInAMonth(short Month, short Year) {
		return NumOfHoursInAMonth(Month, Year) * 60;
	}

	short NumOfMinutesInAMonth() {
		return NumOfMinutesInAMonth(_Month, _Year);
	}

	static int NumOfSecondsInAMonth(short month, short year) {
		return NumOfMinutesInAMonth(month, year) * 60;
	}

	int NumOfSecondsInAMonth() {
		return NumOfSecondsInAMonth(_Month, _Year);
	}


	static short NumberOfDaysFromYearBegining(short year, short month, short day) {

		//2024-2-5;

		short TotalDays = 0;

		for (short i = 1; i <= month - 1; i++) {

			TotalDays += NumOfDaysInAMonth(i, year);
		}

		TotalDays += day;
		return TotalDays;

	}

	short NumberOfDaysFromYearBegining() {
		return NumberOfDaysFromYearBegining(_Year, _Month, _Day);
	}

	static string MonthShortName(short month) {

		string MonthArr[12] =
		{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return MonthArr[month - 1];
	}

	static void ShowMonthCalender(short month, short year) {

		cout << "\n  _______________" << MonthShortName(month) << "_______________  \n";

		cout << "\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

		short NumOfMonDays = NumOfDaysInAMonth(month, year);

		short DayOrder;

		for (short day = 1; day <= NumOfMonDays; day++)
		{

			DayOrder = DayOfWeekOrder(year, month, day);

			if (DayOrder == 0 && day > 1)
				cout << endl;

			if (day == 1)
				cout << setw(5 * DayOrder) << "";

			cout << setw(5) << day;
		}
		cout << "\n  _________________________________  \n";
	}

	static void ShowYearCalender(short year) {
		cout << "\n  --------------------------------  \n";
		cout << "\n\t  Calender - " << year << "\n";
		cout << "\n  --------------------------------  \n";

		for (short i = 1; i <= 12; i++)
		{
			ShowMonthCalender(i, year);
			cout << endl;
		}

	}

	static clsDate ConvertTotalDaysToDate(short TotalDays, short year) {
		clsDate Date;

		short RemainingDays = TotalDays;
		short MonthDays = 0;
		Date._Year = year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumOfDaysInAMonth(Date._Month, year);
			if (RemainingDays > MonthDays) {

				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else {
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day ? true : false) : false)) : false));
	}

	bool IsDateBeforeDate2(clsDate Date2) {

		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2) {


		return Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false;

	}

	bool IsDateEqualDate2(clsDate Date2) {

		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2) {


		return (!IsDate1BeforeDate2(Date1, Date2)) && !IsDate1EqualDate2(Date1, Date2);

	}

	bool IsDateAfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(short Day, short Month, short Year) {

		return Day == NumOfDaysInAMonth(Month, Year);
	}

	bool IsLastDayInMonth() {
		return IsLastDayInMonth(_Day, _Month, _Year);
	}

	static bool IsLastMonthInYear(short Month) {

		return (Month == 12);
	}

	static clsDate AddOneDay(clsDate& Date) {

		if (IsLastDayInMonth(Date.Day, Date.Month, Date.Year)) {
			Date.Day = 1;
			if (IsLastMonthInYear(Date.Month)) {
				Date.Month = 1;
				Date.Year++;
			}
			else
				Date.Month++;

		}
		else {

			Date.Day++;
		}

		return Date;

	}

	void AddOneDay() {
		AddOneDay(*this);
	}

	static void Swap(clsDate& Date1, clsDate& Date2) {

		clsDate Temp;

		Temp.Day = Date1.Day;
		Temp.Month = Date1.Month;
		Temp.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = Temp.Day;
		Date2.Month = Temp.Month;
		Date2.Year = Temp.Year;

	}

	static int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool IncludingEndDay = false) {

		int Days = 0;
		int SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2)) {
			Swap(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);

		}
		return IncludingEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDiffrenceInDays(clsDate Date2, bool IncludingEndDay = false) {

		return GetDiffrenceInDays(*this, Date2, IncludingEndDay);
	}

	static clsDate IncreaseDateByXDays(clsDate& Date, int Days) {

		for (int i = 0; i < Days; i++)
		{
			AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(int Days) {
		IncreaseDateByXDays(*this, Days);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date) {

		for (short i = 0; i < 7; i++)
		{
			AddOneDay(Date);

		}
		return Date;
	}

	void IncreaseDateByOneWeek() {
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(clsDate& Date, int Weeks) {

		for (short i = 0; i < Weeks; i++)
		{
			IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(int Weeks) {
		IncreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date) {

		if (Date.Month == 12) {
			Date.Month = 1;
			Date.Year++;
		}
		else {
			Date.Month++;
		}


		short NumOfDaysInCurrentMonth = NumOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumOfDaysInCurrentMonth) {
			Date.Day = NumOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth() {
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate& Date, int Months) {

		for (int i = 0; i < Months; i++)
		{
			IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(int Months) {
		IncreaseDateByXMonths(*this, Months);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date) {

		//29/2/2000
		Date.Year++;

		short NumberOfDaysInCurrentMonth = NumOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth) {
			Date.Month = NumberOfDaysInCurrentMonth;
		}

		return Date;

	}

	void IncreaseDateByOneYear() {
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate& Date, int Years) {

		Date.Year += Years;

		if (Date.Day == 29 && Date.Month == 2 && !IsLeapYear(Date.Year)) {
			Date.Day = 28;
		}
		return Date;
	}

	void IncreaseDateByXYears(int Years) {
		IncreaseDateByXYears(*this, Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date) {

		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade() {
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short DecadesToAdd, clsDate& Date) {

		for (int i = 0; i < DecadesToAdd; i++)
		{
			IncreaseDateByOneDecade(Date);
		}
		return Date;
	}

	void IncreaseDateByXDecades(short DecadesToAdd) {
		IncreaseDateByXDecades(DecadesToAdd, *this);
	}

	static clsDate IncreaseDateByXDecadesFaster(short DecadesToAdd, clsDate& Date) {

		Date.Year += DecadesToAdd * 10;
		return Date;
	}

	void IncreaseDateByXDecadesFaster(short DecadesToAdd) {
		IncreaseDateByXDecadesFaster(DecadesToAdd, *this);
	}

	static clsDate IncreaseDateByOneCencury(clsDate& Date) {

		Date.Year += 100;
		return Date;

	}

	void IncreaseDateByOneCencury() {
		IncreaseDateByOneCencury(*this);
	}

	static clsDate IncreaseDateByMillennium(clsDate& Date) {

		Date.Year += 1000;
		return Date;
	}

	void IncreaseDateByMillennium() {
		IncreaseDateByMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date) {

		if (Date.Day == 1) {
			if (Date.Month != 1) {
				Date.Month--;

			}
			else {
				Date.Month = 12;
				Date.Year--;

			}
			Date.Day = NumOfDaysInAMonth(Date.Month, Date.Year);
			return Date;
		}

		Date.Day--;
		return Date;



	}

	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate& Date, short Days) {

		for (short i = 0; i < Days; i++)
		{
			DecreaseDateByOneDay(Date);
		}
		return Date;

	}

	void DecreaseDateByXDays(short Days) {
		DecreaseDateByXDays(*this, Days);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {

		for (short i = 0; i < 7; i++)
		{
			DecreaseDateByOneDay(Date);
		}
		return Date;

	}

	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate& Date, short Weeks) {

		for (short i = 0; i < Weeks; i++)
		{
			DecreaseDateByOneWeek(Date);
		}
		return Date;

	}

	void DecreaseDateByXWeeks(short Weeks) {
		DecreaseDateByXWeeks(*this, Weeks);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date) {

		//***************
		if (Date.Month == 1) {
			Date.Month = 12;
			Date.Year--;
		}
		else {
			Date.Month--;

		}
		short NumOfDaysInCurrentMonth = NumOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumOfDaysInCurrentMonth) {
			Date.Day = NumOfDaysInCurrentMonth;
		}
		return Date;

	}

	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate& Date, short Months) {
		for (short i = 0; i < Months; i++)
		{
			DecreaseDateByOneMonth(Date);

		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months) {
		DecreaseDateByXMonths(*this, Months);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date) {

		Date.Year--;

		short NumOfDaysInCurrentMonth = NumOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > NumOfDaysInCurrentMonth) {
			Date.Day = NumOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate& Date, short Years) {

		for (short i = 0; i < Years; i++)
		{
			DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYears(short Years) {
		DecreaseDateByXYears(*this, Years);
	}

	static clsDate DecreaseDateByXYearsFaster(clsDate& Date, short Years) {

		for (short i = 0; i < Years; i++)
		{
			Date.Year--;
		}
		return Date;
	}

	void DecreaseDateByXYearsFaster(short Years) {
		DecreaseDateByXYearsFaster(*this, Years);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date) {

		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate& Date, short Decades) {

		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades) {
		DecreaseDateByXDecades(*this, Decades);
	}

	static clsDate DecreaseDateByOneCencury(clsDate& Date) {

		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCencury() {
		DecreaseDateByOneCencury(*this);
	}

	static clsDate DecreaseDateByXCencury(clsDate& Date, short Cencurys) {

		Date.Year -= Cencurys * 100;
		return Date;
	}

	void DecreaseDateByXCencury(short Cencurys) {
		DecreaseDateByXCencury(*this, Cencurys);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date) {

		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium() {
		DecreaseDateByOneMillennium(*this);
	}

	static short DayOfWeekOrder(short year, short month, short day) {

		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + (12 * a) - 2;

		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	static short DayOfWeekOrder(clsDate Date) {

		return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
	}

	static string DayShortName(short DayOrder) {

		string WeekDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return WeekDays[DayOrder];

	}

	string DayShortName() {
		return DayShortName(DayOfWeekOrder(*this));
	}

	static bool IsEndOfWeek(clsDate Date) {

		short DayIndex = DayOfWeekOrder(Date);
		return DayIndex == 6;

	}

	bool IsEndOfWeek() {

		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date) {

		short DayIndex = DayOfWeekOrder(Date);
		return DayIndex == 5 || DayIndex == 6;

	}

	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date) {

		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay() {
		return IsBusinessDay(*this);

	}

	static short DaysUntillTheEndOfWeek(clsDate Date) {

		return 6 - DayOfWeekOrder(Date);

	}

	short DaysUntillTheEndOfWeek() {
		return DaysUntillTheEndOfWeek(*this);
	}

	short DaysUntillTheEndOfMonth(clsDate Date) {

		clsDate EndOfMonthDate;

		EndOfMonthDate.Day = NumOfDaysInAMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;


		return GetDiffrenceInDays(Date, EndOfMonthDate, true);

	}

	short DaysUntillTheEndOfMonth() {
		return DaysUntillTheEndOfMonth(*this);
	}

	short DaysUntillTheEndOfYear(clsDate Date) {

		clsDate EndOfYearDate;

		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDiffrenceInDays(Date, EndOfYearDate, true);

	}

	short DaysUntillTheEndOfYear() {
		return DaysUntillTheEndOfYear(*this);
	}

	static short CalculateBussinessDays(clsDate DateFrom, clsDate DateTo) {

		short Days = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom)) {
				Days++;

			}
			DateFrom.AddOneDay();
		}
		return Days;
	}

	static short CalcAcutalVacationDays(clsDate DateFrom, clsDate DateTo) {

		return CalculateBussinessDays(DateFrom, DateTo);
	}

	static clsDate CalcVacationReturnDate(clsDate StartDate, short VacationDays) {

		clsDate ReturnDate;
		ReturnDate = StartDate;

		while (VacationDays > 0)
		{
			if (IsBusinessDay(ReturnDate)) {
				VacationDays--;
			}
			if (VacationDays == 0) break;
			AddOneDay(ReturnDate);
		}
		return ReturnDate;

	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2) {

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		else if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		else
			return enDateCompare::After;

	}

	enDateCompare CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}

	//static string GetSystemTimeString() {

	//	time_t timestamp = time(&timestamp);
	//	struct tm datetime = *localtime(&timestamp);

	//	return to_string(datetime.tm_hour) + ":" + to_string(datetime.tm_min) + ":" + to_string(datetime.tm_sec);
	//	
	//}



};
