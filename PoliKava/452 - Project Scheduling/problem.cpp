#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

map< char, vector<char> > g;
map<char,int> days, dp;

int walk(char node)
{
	if (dp[node] != INF)
		return dp[node];

	int max_neighbors = 0;
	for(auto &nbr : g[node])
		max_neighbors = max(max_neighbors, walk(nbr));
	
	max_neighbors += days[node];
	print("\nTotal time to complete task %c: %d", node, max_neighbors);
	return dp[node] = max_neighbors;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	getchar();
	string blank;
	getline(cin, blank);

	FOR(tc, TC)
	{
		int cdays;
		char target;

		if (tc)
			printf("\n");

		g.clear();
		dp.clear();
		days.clear();
		while(1)
		{
			if (scanf("%c", &target) != 1)
				break;
			if (target == '\n')
				break;
			print("OEILA");
			scanf("%d", &cdays);
			days[target] = cdays;
			dp[target] = INF;

			if (g.find(target) == g.end())
				g[target] = {};

			while(1)
			{
				char c = getchar();
				if (c == '\n' || c == EOF)
					break;
				else if (c == ' ')
					continue;
				else
					g[target].push_back(c);
			}
		}

		/*for(auto &nbr : g)
		{
			print("\nNode %c has %lu neighbors", nbr.first, nbr.second.size());
			for(auto &nbrs : nbr.second)
				print("\n  > %c", nbrs);
		}*/

		for(auto &node : g)
		{
			if (dp[node.first] == INF)
			{
				walk(node.first);
			}
		}

		int mvalue = 0;
		for(auto &node : g)
			mvalue = max(mvalue, dp[node.first]);
		printf("%d\n", mvalue);
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