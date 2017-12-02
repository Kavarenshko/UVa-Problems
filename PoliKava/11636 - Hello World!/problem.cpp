#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int main()
{
	int N;
	FOR1(tc, INF)
	{
		scanf("%d", &N);
		if (N < 0)
			break;
		printf("Case %d: ", tc);

		if (N == 1)
		{
			printf("0\n");
			continue;
		}

		int tot = 1, paste = 0;
		while(tot != N)
		{
			if (tot * 2 <= N)
			{
				tot *= 2;
				paste += 1;
			}
			else
			{
				tot += (N - tot);
				paste += 1;
			}
		}
		printf("%d\n", paste);
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