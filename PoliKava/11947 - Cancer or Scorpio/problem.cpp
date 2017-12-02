#include <iostream>
#include <string>

#define PREGNANCY 40 * 7

using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string zodiac_signs[12] = {"aquarius","pisces","aries","taurus","gemini","cancer","leo","virgo","libra","scorpio","sagittarius","capricorn"};

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

int getZodiacIndex(struct data& d)
{
	if ((d.month == 1 && d.day >= 21) || (d.month == 2 && d.day <= 19))
		return 0;
	else if ((d.month == 2 && d.day >= 20) || (d.month == 3 && d.day <= 20))
		return 1;
	else if ((d.month == 3 && d.day >= 21) || (d.month == 4 && d.day <= 20))
		return 2;
	else if ((d.month == 4 && d.day >= 21) || (d.month == 5 && d.day <= 21))
		return 3;
	else if ((d.month == 5 && d.day >= 22) || (d.month == 6 && d.day <= 21))
		return 4;
	else if ((d.month == 6 && d.day >= 22) || (d.month == 7 && d.day <= 22))
		return 5;
	else if ((d.month == 7 && d.day >= 23) || (d.month == 8 && d.day <= 21))
		return 6;
	else if ((d.month == 8 && d.day >= 22) || (d.month == 9 && d.day <= 23))
		return 7;
	else if ((d.month == 9 && d.day >= 24) || (d.month == 10 && d.day <= 23))
		return 8;
	else if ((d.month == 10 && d.day >= 24) || (d.month == 11 && d.day <= 22))
		return 9;
	else if ((d.month == 11 && d.day >= 23) || (d.month == 12 && d.day <= 22))
		return 10;
	else
		return 11;
}


int main()
{
	int t,d,m,y;

	scanf("%d", &t);

	for(int i=1; i <= t; i++)
	{
		char c;
		d = 0;
		m = 0;
		y = 0;

		// day

		getc(stdin); // \n
		c = getc(stdin);
		m += 10 * (c-48);
		c = getc(stdin);
		m += c-48;

		//cout << d << "\n";

		// month

		c = getc(stdin);
		d += 10 * (c-48);
		c = getc(stdin);
		d += c-48;

		//cout << m << "\n";

		// year

		c = getc(stdin);
		y += 1000 * (c-48);
		c = getc(stdin);
		y += 100 * (c-48);
		c = getc(stdin);
		y += 10 * (c-48);
		c = getc(stdin);
		y += c-48;
		//cout << y << "\n";

		data start_date = {d,m,y};
		start_date = calcRemaining(start_date, PREGNANCY);

		printf("%d %02d/%02d/%02d %s\n", i, start_date.month, start_date.day, start_date.year, zodiac_signs[getZodiacIndex(start_date)].c_str()); // add zodiac sign
	}

	return EXIT_SUCCESS;
}
