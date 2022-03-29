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
	DateClass birthDay;

	birthDay.m_year = 1991;
	birthDay.m_month = 3;
	birthDay.m_day = 12;
	birthDay.print();

	std::cout << std::endl;

	DateClass birthDay2;
	birthDay2.m_year = 1990;
	birthDay2.m_month = 1;
	birthDay2.m_day = 23;
	birthDay2.print();
	std::cout << std::endl;
}
