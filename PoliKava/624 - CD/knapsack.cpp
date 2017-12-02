#include <bits/stdc++.h>

using namespace std;

int K;
long N, t;
long bestSolution;
vector<long> v, sol, curr;

void walk(long r, int ind)
{
	if (ind == K)
	{
		if (r < bestSolution)
		{
			bestSolution = r;
			sol = curr;
		}
		return;
	}

	walk(r, ind+1); // knapsack 0 : don't take this element

	if (r - v[ind] >= 0)
	{
		curr.push_back(v[ind]);
		walk(r-v[ind], ind+1); // knapsack 1 : take this element
		curr.pop_back();
	}
}

int main()
{
	while(1)
	{
		if (scanf("%ld %d", &N, &K) != 2)
			break;

		bestSolution = 0x7fffffff; // INF
		v.clear();
		sol.clear();
		curr.clear();
		for(int i=0; i < K; i++)
		{
			scanf("%ld", &t);
			v.push_back(t);
		}

		walk(N, 0);

		for(auto &el : sol)
			printf("%ld ", el);
		printf("sum:%ld\n", N-bestSolution);
	}
	return EXIT_SUCCESS;
}