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
int articulations, dfs_counter;
int dfs_root, root_children;
vector<set<int>> g;

vi dfs_num, dfs_low, dfs_parent, is_articulation;

void walk(int u)
{
	dfs_num[u] = dfs_low[u] = dfs_counter++;

	for(int nb : g[u])
	{
		if (dfs_num[nb] == UNVISITED)
		{
			dfs_parent[nb] = u;
			walk(nb);

			if (u == dfs_root)
				root_children += 1;

			if (dfs_low[nb] >= dfs_num[u])
			{
				//print("\nNode %d is an articulation point. (%d)", u, nb);
				is_articulation[u] = 1;
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[nb]);
		}
		else if (nb != dfs_parent[u])
		{
			dfs_low[u] = min(dfs_low[u], dfs_num[nb]);
		}
	}
}

int main()
{
	while(1) // for each test case
	{
		scanf("%d", &N);
		if (!N)
			break;

		//print("\nTC\n\n");

		dfs_counter = 0;
		articulations = 0;
		g.assign(N+1, set<int>());

		dfs_num.clear();
		dfs_num.assign(N+1, UNVISITED);

		dfs_low.clear();
		dfs_low.assign(N+1, UNVISITED);

		dfs_parent.clear();
		dfs_parent.assign(N+1, UNVISITED);

		is_articulation.clear();
		is_articulation.assign(N+1, 0);

		while(1) // for each node with neighbors
		{
			int c_node;
			char detect_newline;

			scanf("%d%c", &c_node, &detect_newline);

			if (c_node == 0) // end of test case, find solution
				break;
			//print("\nTarget: %d", c_node);

			while(1) // for each neighbor
			{
				int nb;
				scanf("%d%c", &nb, &detect_newline);

				g[c_node].insert(nb);
				g[nb].insert(c_node); // bidirectional as stated

				//print("\n  > %d", nb);
				if (detect_newline == '\n')
					break;
			}
		}

		for(int i=1; i <= N; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				dfs_root = i;
				root_children = 0;
				walk(i);

				is_articulation[i] = (root_children > 1);
			}
		}

		for(int i=1; i <= N; i++)
			articulations += is_articulation[i];
		printf("%d\n", articulations);
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