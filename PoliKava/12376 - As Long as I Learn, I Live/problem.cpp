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

int N,M;
int a[MAX];
int sol;
graph g;

int walk(int ind)
{
	if (g[ind].size() == 0)
		return ind;

	int mv,mi;
	mv = mi = -INF;
	for(auto &nbr : g[ind])
	{
		if (a[nbr] > mv)
		{
			mv = a[nbr];
			mi = nbr;
		}
	}
	sol += mv;
	return walk(mi);
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		sol = 0;
		g.assign(MAX, vi());

		printf("Case %d: ", tc);
		scanf("%d %d", &N, &M);
		FOR(i, N)
			scanf("%d", &a[i]);
		FOR(i, M)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
		}
		printf("%d %d\n", sol, walk(0));
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