#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int COIN_DNM = 21;
constexpr int COIN_LIMIT = 10000;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

long long dp[COIN_DNM][COIN_LIMIT];

vector<long long> coins;

void genCoins()
{
	coins.push_back(1);
	for(long long i=8LL; i <= 9261; i++)
	{
		for(long long j=2LL; ; j++)
		{
			long long val = j*j*j;
			if (val > i)
				break;
			else if (val == i)
			{
				coins.push_back(i);
				break;
			}
		}
	}
}

long long walk(int index, long long rem)
{
	//print("HERE %d %lld\n", index, rem);
	if (dp[index][rem] != -1LL)
		return dp[index][rem];

	if (index == 0)
		return (dp[index][rem] = 1LL);

	long long tot = 0LL;
	long long mult = 0LL;
	
	while(coins[index] * mult <= rem)
	{
		//print("ALORA");
		tot += walk(index-1, rem - (coins[index] * mult));
		mult += 1LL;
	}

	return (dp[index][rem] = tot);
}

int main()
{
	long long N;

	genCoins();
	for(auto &el : coins)
		print("\n%lld", el);
	for(int i=0; i < COIN_DNM; i++)
		for(int j=0; j < COIN_LIMIT; j++)
			dp[i][j] = -1LL;

	while(scanf("%lld", &N) == 1)
	{
		if (N == 0LL)
			printf("1\n");
		else
			printf("%lld\n", walk(coins.size()-1, N));
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