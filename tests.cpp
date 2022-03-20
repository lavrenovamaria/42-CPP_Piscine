#include <iostream>

struct DateStruct
{
	int year;
	int month;
	int day;
};

class DateClass
{
	public:
		int m_year;
		int m_month;
		int m_day;

	void print()
	{
		std::cout << m_year << "/" << m_month << "/" << m_day;
	}
};

int main()
{
	DateClass birthDay { 2019, 7, 28 };

	birthDay.m_year = 1992;
	birthDay.print();
}
