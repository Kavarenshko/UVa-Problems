#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> dg; // directed graph
typedef vector<ii> vii;
typedef vector<dg> vdg;

long conjecture(long n)
{
	if (n == 1)
		return n;
	
	if (n % 2 == 0) // even, can't be 0
	{
		return 1 + conjecture(n/2);
	}
	else
	{
		return 1 + conjecture(3*n+1);
	}
}

int main()
{
	long i,j;

	while (cin >> i >> j)
	{
		long max = 0;
		if (i < j)
		{
			for(long k=i; k <= j; k++)
			{
				long res = conjecture(k);
				if (res > max)
					max = res;
			}
			cout << i << " " << j << " " << max << "\n";
		}
		else
		{
			for(long k=j; k <= i; k++)
			{
				long res = conjecture(k);
				if (res > max)
					max = res;
			}
			cout << i << " " << j << " " << max << "\n";
		}
	}

	return EXIT_SUCCESS;
}