#include <iostream>
#include <algorithm>
#include <iomanip>

#define MAX_MONTHS 100

using namespace std;

int main()
{
	int nMonths, changes, current_months;
	double down, loan, monthly_payment;
	double rates[MAX_MONTHS];
	double init_value = -1.0; // avoid nan in memset

	while(1)
	{
		cin >> nMonths >> down >> loan >> changes;

		if (nMonths < 0)
			break;

		fill(rates, rates+MAX_MONTHS, init_value);

		for(int i=0; i < changes; i++)
		{
			int actual_month;
			double rate;

			cin >> actual_month >> rate; // check rate
			rates[actual_month] = rate;
			//cout << "\nRate for month " << i << ": " << rates[i];
		}

		double owed, value, current_rate = rates[0];

		monthly_payment = loan / nMonths;
		owed = loan + down;
		value = loan + down;
		//value -= value * current_rate; // as he drives away, the car's value starts to diminish
		//cout << "Month 0: " << owed << " vs " << value << "\n";

		for(current_months=0; current_months <= nMonths; current_months++)
		{
			if (current_months == 0)
				owed -= down;
			else
				owed -= monthly_payment;
			if (rates[current_months] != -1)
			{
				current_rate = rates[current_months];
				//cout << "NEW RATE: " << current_rate << "\n";
			}
			value -= value * current_rate;

			//cout << "Month " << fixed << setprecision(8) << current_months << ": " << owed << " vs " << value << "\n";

			if (value > owed)
				break;
		}

		if (current_months == 1)
			cout << "1 month\n";
		else
			cout << current_months << " months\n";
	}

	return EXIT_SUCCESS;
}