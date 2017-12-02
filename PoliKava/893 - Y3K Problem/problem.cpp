#include <iostream>

#define YEAR_DURATION 365
#define LEAP_DURATION 366

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct data
{
	int day;
	int month;
	int year;
};

bool isLeapYear(int y)
{
	if (y % 4 == 0)
	{
		if (y % 100 == 0 && y % 400 != 0)
			return false;
		return true;
	}
	return false;
}

bool isLeapYear(struct data& current)
{
    return isLeapYear(current.year);
}

struct data calcRemaining(struct data& d, int r)
{
	// assume r < YEAR_DURATION

	//cout << "  > analyzing " << d.day << " " << d.month << " " << d.year << "..." << r;

	while (r > 0)
	{
		int rem_days;
		if (isLeapYear(d) && d.month == 2)
		{
		    rem_days = days[d.month-1] - d.day + 1;
			//cout << "\n        oeila";
		}
		else
		{
			rem_days = days[d.month-1] - d.day;
			//cout << "\n        ";
		}

		//cout << "> " << rem_days << "/" << r << "   --> ";

		if (r > rem_days)
		{
			if (rem_days == 0)
				r -= 1;
			else
			{
				r -= rem_days+1;
			}
			d.day = 1;
			d.month = (d.month+1);
			if (d.month == 13) // 
			{
				d.month = 1;
				d.year++;
			}
			//cout << d.day << " " << d.month << " " << d.year;
		}
		else if (r == rem_days)
		{
			r = 0;
			if (isLeapYear(d) && d.month == 2)
				d.day = 29;
			else
				d.day = days[d.month-1];
			//cout << "STOP " << d.day << " " << d.month << " " << d.year;
		}
		else
		{
			d.day += r;
			r = 0;
			//cout << "stop " << d.day << " " << d.month << " " << d.year;
		}
		//cout << "\n";
	}
	return d;
}



int main()
{
	int n,d,m,y;

	while(1)
	{
		cin >> n >> d >> m >> y;

		if (!n && !d && !m && !y)
			break;

		if (n == 0)
		{
			cout << d << m << y << "\n";
			continue;
		}

		// get partial year + n full years + final partial year
		data start_date = {d,m,y};
		start_date = calcRemaining(start_date, n);

		cout << start_date.day << " " << start_date.month << " " << start_date.year << "\n";
	}

	return EXIT_SUCCESS;
}