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

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int N,M;
		bool possible = true;

		graph g;
		set<ii> e;

		scanf("%d %d", &N, &M);

		g.assign(N, vi());
		for(auto &el : g)
			el.assign(M, 0);

		FOR(i, N)
			FOR(j, M)
				scanf("%d", &g[i][j]);

		FOR(j, M)
		{
			int col_sum = 0;
			ii current_pair;
			FOR(i, N)
			{
				col_sum += g[i][j];
				if (g[i][j])
				{
					if (col_sum == 1)
						current_pair.first = i;
					else
						current_pair.second = i;
				}
			}

			if (col_sum != 2)
			{
				print("sum\n");
				possible = false;
				break;
			}

			if (e.find(current_pair) != e.end())
			{
				print("pair\n");
				possible = false;
				break;
			}
			else
				e.insert(current_pair);
		}

		if (possible)
			printf("Yes\n");
		else
			printf("No\n");
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