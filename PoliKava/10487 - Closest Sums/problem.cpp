#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX_N 1000
#define INF 0x7FFFFFFF

using namespace std;

long closer(long target, long a, long b)
{
	long n1 = a - target;
	long n2 = b - target;

	if (abs(n1) < abs(n2))
		return n1;
	else
		return n2;
}

int main()
{
	int tc = 0;
	long nums[MAX_N];

	while(1)
	{
		int n, m;
		cin >> n;

		if(!n)
			break;

		tc++;
		cout << "Case " << tc << ":\n";

		memset(nums, INF, MAX_N);
		for(int i=0; i < n; i++)
		{
			cin >> nums[i];
		}

		sort(nums, nums + n); // std::sort

		cin >> m;
		for(int i=0; i < m; i++)
		{
			long curr, closest = -INF;
			bool found = false;

			cin >> curr;
			cout << "Closest sum to " << curr << " is ";

			for(int j=0; j < n; j++)
			{
				for(int k=j+1; k < n; k++)
				{
					long sum = nums[j] + nums[k];

					if (sum == curr)
					{
						found = true;
						closest = 0;
						break;
					}

					closest = closer(curr, curr + closest, sum);
				}
				if (found)
					break;
			}

			cout << curr + closest << ".\n";
		}
	}

	return EXIT_SUCCESS;
}