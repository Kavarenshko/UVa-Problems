#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define MAX_LEN 1000000 + 1
#define MAX_PRICE 4001.0

using namespace std;

int p,a,b,c,d,n;

double getPrice(int k)
{
	return p * (sin(a * k + b) + cos(c * k + d) + 2); // at most 1000 * (1 + 1 + 2) = 4000, so MAX_PRICE is set to 4001.0
}

int main()
{
	double v[MAX_LEN];
	fill(v, v+MAX_LEN, MAX_PRICE);

	while(cin >> p >> a >> b >> c >> d >> n)
	{
		double max_shift = 0.0;

		if (n == 1)
		{
			cout << "0.000000\n";
			continue; // no decline
		}

		for(int i=1; i <= n; i++)
		{
			v[i] = getPrice(i);
		}

		for(int i=n-1; i >= 1; i--) // we can safely start from n-1
		{
			for(int j=i+1; j <= n; j++)
			{
				double current_shift;
				if (v[j] >= v[i]) // increase, stop
					break;
				// v[i] > v[j], j > i
				current_shift = v[i] - v[j];
				max_shift = max(max_shift, current_shift);
			}
		}

		cout << fixed << setprecision(6) << max_shift << "\n";
	}

	return EXIT_SUCCESS;
}