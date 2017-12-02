#include <iostream>
#include <string.h>

#define MAX_COEFFS 21

using namespace std;

long long pow(int n, int exn)
{
	if (exn == 1)
		return n;
	else
		return n * pow(n, exn-1);
}

int main()
{
	int tc;
	int coeffs[MAX_COEFFS];

	cin >> tc;

	while(tc--)
	{
		int i, d, k, n=1;

		cin >> i;
		memset(coeffs, -1, MAX_COEFFS);

		for(int j=0; j <= i; j++)
		{
			cin >> coeffs[j];
		}
		cin >> d >> k;

		while(k)
		{
			if (k > n*d)
			{
				k -= n*d;
				n++;
			}
			else
			{
				long long res = coeffs[0];
				for(int j=1; j <= i; j++)
				{
					res += coeffs[j] * pow(n,j);
				}
				cout << res << "\n";
				k = 0;
			}
		}
	}

	return EXIT_SUCCESS;
}