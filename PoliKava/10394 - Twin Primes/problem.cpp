#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int LIMIT = 20000002;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

vi v;

void gen()
{
	bitset<20000002> bs; bs.set();
	bs[0] = false;
	bs[1] = false;
	for(int i=2; i < LIMIT; i++)
	{
		if (bs[i])
		{
			if (bs[i-2])
				v.push_back(i);
			for(int j=2; i*j < LIMIT; j++)
				bs[i*j] = false;
		}
	}
}

int main()
{
	int N;

	gen();
	while(scanf("%d", &N) == 1)
		printf("(%d, %d)\n", v[N-1] - 2, v[N-1]);

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