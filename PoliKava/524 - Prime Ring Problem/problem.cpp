#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N;
vector<int> v;
vector<int> pos;

bool isPrime(int n)
{
	int p[] = {3,5,7,11,13,17,19,23,29,31,37,43};
	int l = 12;
	FOR(i,l)
		if (n == p[i])
			return true;
	return false;
}

void walk(int put, int prev)
{
	if (put == N) // all numbers are in, check if the last one + 1 is prime
	{
		if (isPrime(prev+1))
		{
			FOR(i, N-1)
				printf("%d ", v[i]);
			printf("%d\n", v.back());
		}
		return;
	}

	for(int i=0; i < pos.size(); i++)
	{
		int c = pos[i];
		if (isPrime(c+prev))
		{
			v.push_back(c);
			pos.erase(pos.begin()+i);
			walk(put+1, c);
			pos.insert(pos.begin()+i, c);
			v.pop_back();
		}
	}
}

int main()
{
	FOR1(tc, INF)
	{
		if (scanf("%d", &N) != 1)
			break;

		if (tc >= 2)
			printf("\n");
		printf("Case %d:\n", tc);

		if (N == 1)
		{
			printf("1\n");
			continue;
		}

		v.clear();
		pos.clear();
		for(int i=2; i <= N; i++)
			pos.push_back(i);
		v.push_back(1);
		walk(1, 1);
		//break;
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