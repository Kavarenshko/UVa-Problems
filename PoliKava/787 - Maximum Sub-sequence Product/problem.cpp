
/*
	WA: need big number support
*/

#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int SEQ = -999999;
constexpr int MAX = 100;

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
	int ind;
	long long t;
	vector<long long> v(MAX,0);
	vector< pair<long long, long long> > dp(MAX, {0,0});
	while(1) // for every sequence
	{
		if (scanf("%lld", &v[0]) != 1)
			break;

		ind = 1;
		while(1) // for every number in the sequence
		{
			scanf("%lld", &t);
			if (t == SEQ)
				break;
			v[ind] = t;
			ind += 1;
		}

		dp[ind-1].first = dp[ind-1].second = v[ind-1];
		for(int i=ind-2; i >= 0; i--)
		{
			dp[i].first = min(v[i], min(v[i] * dp[i+1].first, v[i] * dp[i+1].second));
			dp[i].second = max(v[i], max(v[i] * dp[i+1].first, v[i] * dp[i+1].second));
		}
		long long currMax = -9999999999999999;
		FOR(i, ind)
			currMax = max(currMax, dp[i].second);
		printf("%lld\n", currMax);
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