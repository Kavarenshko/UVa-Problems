#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

bool nodes[26]; // is it used and not visited? if so, true
graph g;

int walk(int node)
{
	int tot = 1;
	nodes[node] = false;
	for(unsigned i=0; i < g[node].size(); i++)
	{
		if (!nodes[g[node][i]])
			continue;
		tot += walk(g[node][i]);
	}
	return tot;
}

int main()
{
	int TC, trees, acorns;

	scanf("%d", &TC);
	getchar();
	FOR(tc, TC)
	{

		print("\n\nTEST CASE - - - - - - -\n\n");

		string connection;
		g.assign(26, vi());
		while(1)
		{
			getline(cin, connection);
			if (connection[0] == '*')
				break;
			char a,b;
			sscanf(connection.c_str(), "(%c,%c)", &a, &b);
			print("\nConnecting %c and %c.", a, b);
			a -= 'A'; b -= 'A';
			g[a].push_back(b);
			g[b].push_back(a);
		}

		getline(cin, connection);
		for(unsigned i=0; i < connection.size(); i += 2)
			nodes[connection[i]-'A'] = true;

		trees = 0;
		acorns = 0;

		for(int i=0; i < 26; i++)
		{
			if (!nodes[i]) // skip as node is not used or already visited
				continue;
			if (walk(i) == 1)
				acorns++;
			else
				trees++;
		}

		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
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