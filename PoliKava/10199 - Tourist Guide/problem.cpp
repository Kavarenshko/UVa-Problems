#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 101;
constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

map< string, vector<string> > g;
map< string, int > dfs_num, dfs_low;
int dfs_count, dfs_child, sol_count;
map< string, bool > cameras;
string dfs_root;
set<string> solution;

void walk(string n, string prev)
{
	print("\nCurrent node: %s, prev: %s, count: %d", n.c_str(), prev.c_str(), dfs_count);
	if (dfs_num[n] == INF)
		dfs_num[n] = dfs_low[n] = dfs_count++;
	else
		*(int*)0 = 0;

	for(auto &nbr : g[n])
	{
		if (nbr == prev)
			continue;
		if (dfs_num[nbr] == INF) // not visited yet
		{
			if (n == dfs_root)
				dfs_child += 1;
			walk(nbr, n);
			if (dfs_low[nbr] >= dfs_num[n])
				cameras[n] = true;
			dfs_low[n] = min(dfs_low[n], dfs_low[nbr]);
		}
		else // cycle
		{
			dfs_low[n] = min(dfs_low[n], dfs_num[nbr]);
		}
	}
}

int main()
{
	int N;
	string n1,n2;
	FOR1(tc, INF) // assuming that the graph is connected
	{
		scanf("%d", &N);
		if (!N)
			break;

		if (tc > 1)
			printf("\n");

		print("\n\n- - - - - - - TEST CASE - - - - - - -\n\n");

		g.clear(); dfs_num.clear(); dfs_low.clear(); cameras.clear(); solution.clear();
		dfs_count = 0;
		sol_count = 0;

		getchar();
		FOR(i, N)
		{
			string node;
			getline(cin, node);
			if (g.find(node) == g.end())
				g[node] = {};
			else
				*(int*)0 = 0;
		}
		scanf("%d", &N);
		getchar();
		FOR(i, N)
		{
			cin >> n1 >> n2;
			print("\nNode between %s and %s", n1.c_str(), n2.c_str());
			g[n1].push_back(n2);
			g[n2].push_back(n1);

			if (dfs_low.find(n1) == dfs_low.end())
			{
				dfs_low[n1] = INF;
				dfs_num[n1] = INF;
				cameras[n1] = false;
			}
			if (dfs_low.find(n2) == dfs_low.end())
			{
				dfs_low[n2] = INF;
				dfs_num[n2] = INF;
				cameras[n2] = false;
			}
		}

		for(auto &nbr : g)
		{
			if (dfs_num[nbr.first] == INF)
			{
				dfs_root = nbr.first;
				dfs_child = 0;
				walk(nbr.first, "random");
				cameras[nbr.first] = (dfs_child > 1);
			}
		}
		for(auto &node : cameras)
		{
			if (node.second)
			{
				solution.insert(node.first); // alphabetical order
				sol_count += 1;
			}
		}
		printf("City map #%d: %d camera(s) found\n", tc, sol_count);
		for(auto &sol : solution)
			printf("%s\n", sol.c_str());
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