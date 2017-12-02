#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int CHOPSTICKS_LIMIT = 5001;
constexpr int GUEST_LIMIT = 3 * 1009;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

vector<long long> v;
long long dp[CHOPSTICKS_LIMIT][GUEST_LIMIT];

inline long long cust_pow(long long value) { return value * value; }

long long walk(int index, int rem)
{
	print("\nAt %d - %d", index, rem);
	if (rem <= 0)
		return *(int*)0 = 0;

	if ((v.size() - index) < rem)
		return (dp[index][rem] = LLONG_MAX);

	if (dp[index][rem] != -1LL)
		return dp[index][rem];

	long long take = cust_pow(v[index] - v[index+1]);
	if (rem - 3 > 0)
		take += walk(index+2, rem-3);

	long long skip = walk(index+1, rem);

	return (dp[index][rem] = min(take, skip));
}

int main()
{
	int TC, K, N;
	scanf("%d", &TC);

	for(int tc=1; tc <= TC; tc++)
	{
		scanf("%d %d", &K, &N);
		K += 8;

		for(int i=0; i <= N; i++)
		{
			for(int j=0; j <= 3*K; j++)
			{
				//print("\nResetting [%d][%d]", i, j);
				dp[i][j] = -1LL;
			}
		}

		v.clear();
		for(int i=0; i < N; i++)
		{
			long long temp; scanf("%lld", &temp);
			v.push_back(temp);
		}
		printf("%lld\n", walk(0, 3*K));
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