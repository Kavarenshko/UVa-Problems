#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX = 21;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int v[MAX], idx[MAX];
int c[MAX];
int dp[MAX];

int main()
{
	int N;
	scanf("%d", &N);
	FOR1(i, N)
	{
		int t;
		scanf("%d", &t);
		v[t] = i;
	}
	FOR1(i,N)
	{
		idx[v[i]] = i;
	}
	bool f = false;
	while(1)
	{
		for(int i=1; i <= N; i++)
		{
			int t;
			if (scanf("%d", &t) != 1)
			{
				f = true;
				break;
			}
			c[t] = i;
		}
		if (f)
			break;

		print("\n");
		for(int i=1; i <= N; i++)
			print("%d ", idx[i]);
		print("\n");
		for(int i=1; i <= N; i++)
			print("%d ", c[i]);

		dp[N] = 1;
		for(int i=N-1; i > 0; i--)
		{
			dp[i] = 1;
			for(int j=i+1; j <= N; j++)
			{
				print("\nIndex of %d is %d and index of %d is %d", idx[c[i]], i, idx[c[j]], j);
				if (idx[c[i]] < idx[c[j]])
					dp[i] = max(dp[i], dp[j]+1);
			}
			print("\nFinal dp[%d] : %d", i, dp[i]);
		}
		int lis = 0;
		FOR1(i, N)
			lis = max(lis, dp[i]);
		printf("%d\n", lis);
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