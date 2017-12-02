#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int COIN_DNM = 5;
constexpr int COIN_LIMIT = 30001;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

long long dp[COIN_DNM][COIN_LIMIT];

long long coins[] = {1LL, 5LL, 10LL, 25LL, 50LL};

long long walk(int index, long long rem)
{
	if (dp[index][rem] != -1LL) // solution already calculated
		return dp[index][rem];

	if (index == 0) // there is only one way to give change with 1c coins
		return (dp[index][rem] = 1LL);

	long long tot = 0LL; // saves # of combinations
	long long mult = 0LL; // number of coins of this value used (0 means skip this coin)
	while(coins[index] * mult <= rem) // try with 0,1,2,...,N coins of this value
	{
		tot += walk(index-1, rem - (coins[index] * mult)); // and with these N coins, go on with smaller values
		mult += 1LL; // next cycle use one more coin of this value
	}

	return (dp[index][rem] = tot); // save the result for future use
}

int main()
{
	long long N;
	long long value;

	for(int i=0; i < COIN_DNM; i++)
		for(int j=0; j < COIN_LIMIT; j++)
			dp[i][j] = -1LL;

	while(scanf("%lld", &N) == 1)
	{
		value = walk(4, N);

		if (value == 1LL)
			printf("There is only 1 way to produce %lld cents change.\n", N);
		else
			printf("There are %lld ways to produce %lld cents change.\n", value, N);
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