#pragma once
#include <math.h>
#include <exception>
class MyDate{
	int year, month, day;
	void set(int y, int m, int d) throw(std::out_of_range);
public:
	MyDate(int y,int m,int d)throw(std::out_of_range);
	bool isLeapYear() const;
	int maxDay() const;
	int day_t() const;
	friend int operator-(const MyDate& a, const MyDate& b);
};
MyDate::MyDate(int y,int m,int d)throw(std::out_of_range) {
	set(y,m,d);
}

void MyDate::set(int y, int m, int d) throw(std::out_of_range) {
	if (y < 1 || m < 1 || m>12 || d<1) throw std::out_of_range("不存在该日期");
	year = y; month = m; day = d;
	if (day > maxDay()) throw std::out_of_range("不存在该日期");
}
bool MyDate::isLeapYear() const {
	return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}
int MyDate::maxDay() const {
	int M[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear() && month == 2)
		return 29;
	else
		return M[month - 1];
}
int MyDate::day_t() const {
	int M[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	for (int i = 0; i < month - 1; i++)
		sum = sum + M[i];
	if (isLeapYear() && month>2)
		sum++;
	return 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + sum + day - 1;
}
int operator-(const MyDate& a,const MyDate& b) {
	return a.day_t() - b.day_t();
}