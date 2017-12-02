#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_DECK = 2003;
typedef pair<int, int> ii;

unsigned long sums[MAX_DECK];

int main()
{
	int n;

	sums[0] = 0; // useless
	sums[1] = 1;

	for(int i=2; i < MAX_DECK; i++)
		sums[i] = sums[i-1] + i;

	scanf("%d", &n);
	while(n--)
	{
		ii p;
		scanf("%d %d", &p.first, &p.second);
		printf("%lu\n", sums[p.first + p.second] + 1 + p.first);
	}

	return EXIT_SUCCESS;
}