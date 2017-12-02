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
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int N,M,tot = 0;
		scanf("%d %d", &N, &M);

		N -= 2;
		M -= 2;
		if (M % 3 == 0)
			tot += M/3;
		else
			tot += (M/3)+1;
		if (N % 3 == 0)
			tot *= N/3;
		else
			tot *= (N/3)+1;
		printf("%d\n", tot);
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