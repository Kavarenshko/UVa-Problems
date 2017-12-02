#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int main()
{
	int TC,a,b;
	scanf("%d", &TC);
	FOR1(tc, TC)
	{
		scanf("%d %d", &a, &b);
		int tsum = 0;
		for(int i=a; i <= b; i++)
		{
			if (i % 2 != 0)
				tsum += i;
		}
		printf("Case %d: %d\n", tc, tsum);
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