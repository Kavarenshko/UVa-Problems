#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N,M,c;
vi incoming;
graph g;

void walk(int n)
{
	c += 1;
	if (c == N)
		printf("%d\n", n);
	else
		printf("%d ", n);

	for(auto &nbr : g[n])
	{
		if (incoming[nbr] == 1)
			walk(nbr);
		else
			incoming[nbr] -= 1;
	}
}

int main()
{
	FOR(tc, INF)
	{
		scanf("%d %d", &N, &M);
		if (!N && !M)
			break;
		c = 0;
		incoming.assign(N+1, 0);
		g.assign(N+1, vi());
		FOR(i,M)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			incoming[b] += 1;
		}

		for(int i=1; i <= N; i++)
			if (incoming[i] == 0)
				walk(i);
	}
	return EXIT_SUCCESS;
}

void print(const char* msg, ...)
{
	#ifndef ONLINE_JUDGE
		va_list argptr;
		va_start(argptr, msg);
		vfprintf(stderr, msg, argptr);
		va_end(argptr);
	#endif
}