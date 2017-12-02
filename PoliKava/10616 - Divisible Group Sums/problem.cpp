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
typedef tuple<int, int, long long> status;

void print(const char* msg, ...);

int N,Q;
long long D;
vector<long long> v;

long long dp[230][40][40];

long long walk(unsigned index, int rem, long long csum)
{
	if (index >= v.size())
		return 0LL;

	if (dp[index][rem][csum % D] != -1LL)
		return dp[index][rem][csum % D];

	long long take = 0LL;
	long long skip = 0LL;

	if (rem > 1)
		take = walk(index+1, rem-1, (csum + v[index]) % D);
	else
		take += (((csum + v[index]) % D) == 0LL);

	skip = walk(index+1, rem, csum);

	return (dp[index][rem][csum] = take + skip);
}

int main()
{
	for(int sn=1; ; sn++)
	{
		scanf("%d %d", &N, &Q);
		if (N == 0 && Q == 0)
			break;

		printf("SET %d:\n", sn);

		v.clear();
		for(int i=0; i < N; i++)
		{
			long long temp; scanf("%lld", &temp);
			v.push_back(temp);
		}

		for(int i=1; i <= Q; i++)
		{
			int M;

			scanf("%lld %d", &D, &M);

			for(int j=0; j < 230; j++)
				for(int k=0; k < 40; k++)
					for(int t=0; t < 40; t++)
						dp[j][k][t] = -1LL;

			printf("QUERY %d: %lld\n", i, walk(0, M, 0));
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