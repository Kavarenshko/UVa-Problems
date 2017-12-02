#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int INIT_VALUE = INF;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

vii v;
int dist[11][11];
int minpath, b;

string getState(int s)
{
	string ns = "";
	for(int i=b; i >= 0; i--)
		ns += (s & (1 << i))? '1' : '0';
	return ns;
}

void walk(int node, int state, int d)
{
	if (d >= minpath)
		return;

	bool full = true;
	for(int i=0; i <= b; i++)
	{
		if (state & (1 << i))
			continue;

		full = false;
		walk(i, state | (1 << i), d + dist[node][i]);
	}

	if (full)
		minpath = min(minpath, d + dist[node][0]);
}

int main()
{
	int TC;
	scanf("%d", &TC);

	while(TC--)
	{
		int kx, ky;

		scanf("%*d %*d %d %d %d", &kx, &ky, &b); // skip world size

		v.clear();
		minpath = INF;
		v.push_back({kx, ky}); // starting node

		FOR(i, b)
		{
			scanf("%d %d", &kx, &ky);
			v.push_back({kx, ky});
		}

		for(int i=0; i <= b; i++)
			for(int j=0; j <= b; j++)
				dist[i][j] = abs((v[i].first - v[j].first)) + abs((v[i].second - v[j].second));

		walk(0,1,0);

		printf("The shortest path has length %d\n", minpath);
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