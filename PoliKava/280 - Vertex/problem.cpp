#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int LIMIT = 101;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

graph g;
bool visited[LIMIT];

int walk(int n, bool starting)
{
	int tot;

	if (!starting)
	{
		visited[n] = true;
		tot = 1;
	}
	else
		tot = 0;

	for(unsigned i=0; i < g[n].size(); i++) // visit every neighbor
	{
		if (!visited[g[n][i]])
			tot += walk(g[n][i], false);
	}
	return tot;
}

int main()
{
	int N;

	while(1)
	{
		scanf("%d", &N);
		if (!N)
			break;

		g.assign(N+1, vi());

		int starting_node;
		while(1) // read starting node
		{
			scanf("%d", &starting_node);
			if (!starting_node)
				break;

			while(1) // read its edges
			{
				int conn;
				scanf("%d", &conn);

				if (!conn)
					break;
				g[starting_node].push_back(conn);
			}
		}

		int queries;
		scanf("%d", &queries);
		FOR(i, queries)
		{
			FOR1(j, N)
				visited[j] = false;

			int current_start;
			scanf("%d", &current_start);
			printf("%d", N-walk(current_start, true));

			FOR1(j, N)
			{
				if (!visited[j])
					printf(" %d", j);
			}
			printf("\n");
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