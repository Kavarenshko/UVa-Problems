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
	int N,M,count;
	set<int> s;

	while(1)
	{
		int t;
		scanf("%d %d", &N, &M);
		if (!N && !M)
			break;

		s.clear();
		count = 0;
		FOR(i, N)
		{
			scanf("%d", &t);
			s.insert(t);
		}

		FOR(i, M)
		{
			scanf("%d", &t);
			if (s.find(t) != s.end())
				count++;
		}
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