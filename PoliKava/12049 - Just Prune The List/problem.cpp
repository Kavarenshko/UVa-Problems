#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int LIMIT = 10001;

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
		int N,M,t,count;
		map<int, ii> m;

		scanf("%d %d", &N, &M);

		count = 0;
		m.clear();

		FOR(i, N)
		{
			scanf("%d", &t);
			if (m.find(t) == m.end())
				m[t] = {1, 0};
			else
				m[t].first += 1;
		}
		FOR(i, M)
		{
			scanf("%d", &t);
			if (m.find(t) == m.end())
				m[t] = {0, 1};
			else
				m[t].second += 1;
		}

		for(auto &p : m)
			count += abs(p.second.first - p.second.second);
		
		printf("%d\n", count);
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