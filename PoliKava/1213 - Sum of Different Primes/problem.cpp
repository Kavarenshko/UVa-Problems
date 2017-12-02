#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int LIMIT = 1130;
constexpr int PRIMES = 500;
constexpr int KMAX = 16;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N,K;
int dp[LIMIT][PRIMES][KMAX];
vi primes;

void populate()
{
	primes.clear();
	primes.push_back(2);
	for(int i=3; i <= LIMIT; i++)
	{
		bool prime = true;
		for(auto &p : primes)
		{
			if (i % p == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
			primes.push_back(i);
	}
}

int walk(int rem, unsigned ind, int count)
{	
	if (dp[rem][ind][count] != -1)
		return dp[rem][ind][count];

	if (count <= 0 || ind >= primes.size())
		return 0;

	if (rem < primes[ind])
		return dp[rem][ind][count] = 0;
	else if (rem == primes[ind])
	{
		if (count == 1)
			return dp[rem][ind][count] = 1;
		else
			return dp[rem][ind][count] = 0;
	}

	return dp[rem][ind][count] = walk(rem, ind+1, count) + walk(rem - primes[ind], ind+1, count-1);
}

int main()
{
	populate();
	FOR(i, LIMIT)
		FOR(j, PRIMES)
			FOR(k, KMAX)
				dp[i][j][k] = -1;
	while(1)
	{
		scanf("%d %d", &N, &K);
		if (!N && !K)
			break;

		printf("%d\n", walk(N,0,K));
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