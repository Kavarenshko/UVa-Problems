#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;

	cin >> t;
	for(int i=1; i <= t; i++)
	{
		int a,b,c;
		int min_n, max_n;

		cin >> a >> b >> c;

		min_n = min(min(a,b), c);
		max_n = max(max(a,b), c);

		if ((a != min_n) && (a != max_n))
			cout << "Case " << i << ": " << a << "\n";
		else if ((b != min_n) && (b != max_n))
			cout << "Case " << i << ": " << b << "\n";
		else
			cout << "Case " << i << ": " << c << "\n";
	}

	return EXIT_SUCCESS;
}