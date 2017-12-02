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

inline ll exp2c(int e) { return (e == 1)? 2 : 2*exp2c(e-1); }
inline int summ(int s) { return (s == 1)? 1 : s+summ(s-1);}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int N;
		scanf("%d", &N);
		printf("%lld\n", max(exp2c(N+1)-4,1LL));
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