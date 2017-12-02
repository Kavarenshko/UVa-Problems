#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX = 200;
constexpr int NONE = 0;
constexpr int A = -1;
constexpr int B = 1;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

graph g;
int N,E;
bool v[MAX];
int col[MAX];

bool walk(int n)
{
	v[n] = true;
	for(unsigned i=0; i < g[n].size(); i++)
	{
		if (col[g[n][i]] == NONE) // give it a colour
		{
			if (col[n] == A)
				col[g[n][i]] = B;
			else
				col[g[n][i]] = A;
		}
		else
		{
			if (col[g[n][i]] == col[n])
				return false;
			// else skip
		}
		if (!v[g[n][i]])
			return walk(g[n][i]);
	}
	return true;
}

int main()
{
	while(1)
	{
		scanf("%d", &N);
		if (!N)
			break;
		scanf("%d", &E);

		g.clear();
		g.assign(N, vi());
		FOR(i, MAX)
		{
			v[i] = false;
			col[i] = NONE;
		}

		FOR(i, E)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
		}

		col[0] = A;
		if (walk(0))
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
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