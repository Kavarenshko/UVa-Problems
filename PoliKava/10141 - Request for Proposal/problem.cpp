#include <iostream>

#define MAX_LENGTH 80
#define MAX_INT 0x7fffffff

using namespace std;

struct company
{
	char name[MAX_LENGTH];
	double compliance; // 1 if all requirements are met
	double price;

	int company_id; // input order

	bool operator>(struct company& a) const
	{
		if (compliance > a.compliance)
		{
			return true;
		}
		else if (compliance == a.compliance)
		{
			if (price < a.price)
				return true;
			else if (price == a.price)
				return company_id < a.company_id? true:false;
		}
		return false;
	}
};



int main()
{
	int counter=1;
	int p;
	double n;

	while(1)
	{
		cin >> n >> p;

		if (!n && !p)
			break;

		if (counter > 1)
			cout << "\n";

		getc(stdin);
		for(int i=0; i < n; i++) // skip official requirements
		{
			char c;
			while(1)
			{
				c = getc(stdin);
				if (c == '\n' || c == '\0') // '\0' check should not be neccessary
					break;
			}
		}

		company best = {"RANDOM", -0.1, 100000.0, MAX_INT};

		for(int i=0; i < p; i++) // for every company that has made a proposal
		{
			//cout << "\nCURRENT I " << i << " - ";
			company current;
			current.company_id = i;
			fill(current.name, current.name+80, '\0');
			for(int j=0; j < MAX_LENGTH; j++)
			{
				char c = getc(stdin);
				if (c != '\n' && c != '\0')
				{
					current.name[j] = c;
				}
				else
					break;
			}
			cin >> current.price >> current.compliance;

			//cout << current.name << "*" << current.price << "*" << current.compliance;

			getc(stdin);
			for(int j=0; j < current.compliance; j++) // skip requirements
			{
				char c;
				while(1)
				{
					c = getc(stdin);
					if (c == '\n' || c == '\0') // '\0' check should not be neccessary
						break;
				}
			}

			//cout << "OUT";

			current.compliance = current.compliance / n;
			//cout << "\nCurrent company: " << current.name << ", compliance " << current.compliance << ", price " << current.price << ", ID " << current.company_id;

			if (current > best)
			{
				best = current;
				//cout << " best";
			}
			//cout << "\n";
		}

		cout << "RFP #" << counter << "\n" << best.name << "\n";
		counter++;
	}

	return EXIT_SUCCESS;
}