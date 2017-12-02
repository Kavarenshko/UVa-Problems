#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_SIZE = 10010;
constexpr int INF = 0x7fffffff;

typedef pair<int, int> ii;

int b[MAX_SIZE];
int nbooks, amount;
set<int> v;

int DEC(int s)
{
	int s_index, f_index, mid;

	s_index = 0;
	f_index = nbooks-1;

	while(1)
	{
		mid = (s_index + f_index)/2;

		if (b[mid] == s)
			return mid;
		else if (b[mid] > s)
			f_index = mid-1;
		else
			s_index = mid+1;

		if (s_index == f_index)
		{
			if (b[s_index] == s)
				return s_index;
			else
				return -1;
		}
	}
}

int main()
{
	ii best;

	while(1)
	{
		if (scanf("%d", &nbooks) == EOF)
			break;

		best = {0, INF};
		v.clear();
		for(int i=0; i < nbooks; i++)
		{
			scanf("%d", &(b[i]));
			v.insert(b[i]);
		}
		scanf("%d", &amount);

		sort(b, b+nbooks);
		for(int i=0; i < nbooks; i++)
		{
			if (b[i] >= amount)
				break;

			if (v.count(amount-b[i]) == 0)
				continue;

			int match = DEC(amount-b[i]); // always > 0

			if (match == i)
				continue;

			if (match != -1) // match found
			{
				if (abs(b[i] - b[match]) < (best.second-best.first))
				{
					if (b[i] < b[match])
					{
						best.first = b[i];
						best.second = b[match];
					}
					else if (b[i] == b[match])
					{
						best.first = best.second = b[i];
						break;
					}
					else
					{
						best.first = b[match];
						best.second = b[i];
					}
				}
			}
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", best.first, best.second);
	}

	return EXIT_SUCCESS;
}