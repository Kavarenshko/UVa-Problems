#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 10100;
constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N;
ll dp[MAX];

int main()
{
	bool lstreak;
	while(1)
	{
		scanf("%d", &N);
		if (!N)
			break;

		lstreak = true;

		FOR(i, N)
		{
			int a;
			scanf("%d", &a);
			if (a > 0)
				lstreak = false;
			dp[i] = a;
		}

		if (lstreak)
			printf("Losing streak.\n");
		else
		{
			if (N == 1)
			{
				printf("The maximum winning streak is %lld.\n", dp[0]);
				continue;
			}
			for(int i=N-2; i >= 0; i--)
			{
				if (dp[i+1] > 0)
					dp[i] += dp[i+1];
			}
			ll mvalue = 0;
			FOR(i, N)
				mvalue = max(mvalue, dp[i]);
			printf("The maximum winning streak is %lld.\n", mvalue);
		}
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