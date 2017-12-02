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

inline ll cust_exp(long long n, long long e) { return (e == 1)? n : n * cust_exp(n, e-1); }

vector<long long> prime_list;

void primes(const long long limit)
{
	long long res;
	bitset<1000001> bs; bs.set();

	for(long long i=2; i <= limit; i++)
	{
		if (bs[i]) // prime
		{
			for(long long j=2; j < INF; j++)
			{
				res = i*j;
				if (res > limit)
					break;
				bs[res] = false;
			}
			prime_list.push_back(i);
		}
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);

	primes(1000000LL);
	FOR(tc, TC)
	{
		ll a,b,res,tot=0;
		scanf("%lld %lld", &a, &b);

		for(auto &p : prime_list)
		{
			if (p * p > b)
				break;
			for(long long j=2; j < INF; j++)
			{
				res = cust_exp(p, j);
				if (res > b)
					break;
				if (res >= a)
					tot += 1;
			}
		}
		printf("%lld\n", tot);
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