#include <iostream>

using namespace std;

int main()
{
	int t;

	cin >> t;

	while(t--) // for every test case
	{
		long a,b; // long should be superfluous

		cin >> a >> b;

		if (a < b)
			cout << "<\n";
		else if (a > b)
			cout << ">\n";
		else
			cout << "=\n";
	}

	return EXIT_SUCCESS;
}