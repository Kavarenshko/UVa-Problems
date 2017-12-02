#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int EXT_NUMBER = 10000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

vector< vector< pair<int, ii> > > g;
set<int> s; // record visited nodes

int walk(int d, int call_time)
{
	if (s.find(d) == s.end())
		s.insert(d);
	else // already visited
		return 9999;

	for(auto &p : g[d]) // for every time he's absent
	{
		if (call_time >= p.second.first && call_time <= p.second.second)
			return walk(p.first, call_time);
	}
	return d;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	printf("CALL FORWARDING OUTPUT\n");
	FOR1(tc, TC)
	{
		printf("SYSTEM %d\n", tc);

		g.assign(EXT_NUMBER, vector< pair<int, ii> >());
		while(1)
		{
			int source, dest, start, duration;
			scanf("%d", &source);

			if (!source) // end of data
				break;

			scanf("%d %d %d", &start, &duration, &dest);
			g[source].push_back({ dest, {start, start + duration} });
		}

		while(1)
		{
			int call_time, dest;
			scanf("%d", &call_time);

			if (call_time == 9000)
				break;

			s.clear();
			scanf("%d", &dest);
			printf("AT %04d CALL TO %04d RINGS %04d\n", call_time, dest, walk(dest, call_time));
		}
	}
	printf("END OF OUTPUT\n");

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