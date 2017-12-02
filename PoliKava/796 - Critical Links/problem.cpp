#include <bits/stdc++.h>

#define UNVISITED -1

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

int N;
int dfs_counter;

graph g;

vector<ii> bridges;
vi dfs_num, dfs_low, dfs_parent;

void walk(int u)
{
	dfs_num[u] = dfs_low[u] = dfs_counter++;

	for(unsigned i=0; i < g[u].size(); i++)
	{
		int nb = g[u][i];

		if (dfs_num[nb] == UNVISITED)
		{
			dfs_parent[nb] = u;
			walk(nb);

			if (dfs_low[nb] > dfs_num[u]) // bridge
			{
				if (nb < u)
					bridges.push_back({nb, u});
				else
					bridges.push_back({u, nb});
			}
				
			dfs_low[u] = min(dfs_low[u], dfs_low[nb]); // affects intermediate nodes
		}
		else if (nb != dfs_parent[u]) // back edge (avoid back edge to parent)
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[nb]);
		}
	}
}

int main()
{
	for(int tc=0; ; tc++)
	{
		if (scanf("%d", &N) < 1)
			break;

		dfs_counter = 0;

		g.clear();
		g.assign(N+1, vi());

		bridges.clear();

		dfs_num.clear();
		dfs_num.assign(N+1, UNVISITED);

		dfs_low.clear();
		dfs_low.assign(N+1, UNVISITED);

		dfs_parent.clear();
		dfs_parent.assign(N+1, UNVISITED);

		for(int i=0; i < N; i++)
		{
			int node, nb_number;
			scanf("%d (%d)", &node, &nb_number);

			for(int j=0; j < nb_number; j++)
			{
				int nb;
				scanf("%d", &nb);

				g[node].push_back(nb);
			}
		}

		for(int i=0; i < N; i++)
		{
			if (dfs_num[i] == UNVISITED)
				walk(i);
		}

		sort(bridges.begin(), bridges.end());
		printf("%lu critical links\n", bridges.size());
		for(auto &bridge : bridges)
			printf("%d - %d\n", bridge.first, bridge.second);
		printf("\n");
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