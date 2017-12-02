#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;
constexpr int UNVISITED = 0;
constexpr int BS1 = 1;
constexpr int BS2 = 2; // bipartite graph set

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

map< int,int > bg; // not sure if nodes are in range 1-300
map< int, vector<int> > g;

bool walk(int ind, int value)
{
	bg[ind] = value;
	for(auto &nbr : g[ind])
	{
		if (bg[nbr] == UNVISITED)
			walk(nbr, (value == BS1)? BS2 : BS1);
		else
		{
			if (bg[nbr] == bg[ind])
				return false;
		}
	}
	return true;
}

int main()
{
	int N;
	while(1)
	{
		scanf("%d", &N);
		if (!N)
			break;

		bool possible = true;
		g.clear(); bg.clear();

		while(1)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			if (!a && !b)
				break;

			if (g.find(a) == g.end())
			{
				g[a] = {b};
				bg[a] = UNVISITED;
			}
			else
				g[a].push_back(b);

			if (g.find(b) == g.end())
			{
				g[b] = {a};
				bg[b] = UNVISITED;
			}
			else
				g[b].push_back(a);
		}
		for(auto &node : bg)
		{
			if (node.second == UNVISITED)
				possible = possible && walk(node.first, BS1);
		}

		printf("%s\n", (possible)? "YES" : "NO");
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