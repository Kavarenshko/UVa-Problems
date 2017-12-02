#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s;

string nextPermutation(string s)
{
	// assume s.length() > 2

	bool change = false;

	for(int i=(s.length()-2); i >= 0; i--)
	{
		int minOfGreater = 0x7fffffff;
		int ind = 0;
		for(int j=i+1; j <= (s.length()-1); j++)
		{
			if (s[j] > s[i] && s[j] <= minOfGreater) // we include the equal case because less significant digits are better
			{
				minOfGreater = s[j];
				ind = j;
				change = true;
			}
		}

		if (change)
		{
			swap(s[i], s[ind]);
			sort(s.begin()+i+1, s.end());
			return s;
		}
	}

	return "No Successor";
}

int main()
{
	while(getline(cin, s))
	{
		if (s == "#")
			break;

		if (s.length() == 1)
		{
			cout << "No Successor\n";
			continue;
		}
		else if (s.length() == 2 && (s[0] > s[1]))
		{
			cout << "No Successor\n";
			continue;
		}

		cout << nextPermutation(s) << "\n";
	}

	return EXIT_SUCCESS;
}