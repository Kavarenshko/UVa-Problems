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

int N, TC;
map<int, vi> g;
set<int> visited;
set<ii> states;

void walk(int u, int rem)
{
	visited.insert(u);
	states.insert({u, rem});
	if (rem == 0)
		return;

	for(unsigned i=0; i < g[u].size(); i++)
	{
		int nb = g[u][i];
		if (states.count({nb, rem-1}) == 0)
			walk(nb, rem-1);
	}
}

int main()
{
	TC = 1;
	while(1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;

		g.clear();
		for(int i=0; i < N; i++)
		{
			int a,b;
			scanf("%d %d", &a, &b);

			g[a].push_back(b);
			g[b].push_back(a);
		}

		for(;; TC++)
		{
			int starting_node, ttl;
			scanf("%d %d", &starting_node, &ttl);

			if (starting_node == 0 && ttl == 0)
				break;

			visited.clear();
			states.clear();

			if (g.count(starting_node) == 0)
				printf("Case %d: %lu nodes not reachable from node %d with TTL = %d.\n", TC, g.size(), starting_node, ttl);
			else
			{
				walk(starting_node, ttl);
				printf("Case %d: %ld nodes not reachable from node %d with TTL = %d.\n", TC, g.size() - visited.size(), starting_node, ttl);
			}
		}
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