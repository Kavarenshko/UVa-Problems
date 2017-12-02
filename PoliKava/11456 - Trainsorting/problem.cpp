#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 2010;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N;
int a[MAX];
int lis[MAX], lds[MAX];

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		scanf("%d", &N);

		FOR(i, N)
		{
			scanf("%d", &a[i]);
			lis[i] = lds[i] = 0;
		}

		if (N == 0)
		{
			printf("0\n");
			continue;
		}
		else if (N == 1)
		{
			printf("1\n");
			continue;
		}

		int mvalue = -1;
		for(int i=N-1; i >= 0; i--)
		{
			for(int j=i+1; j < N; j++)
			{
				if (a[i] > a[j])
					lds[i] = max(lds[i], lds[j]);
				else if (a[i] < a[j])
					lis[i] = max(lis[i], lis[j]);
			}
			lis[i] += 1;
			lds[i] += 1;
			mvalue = max(mvalue, lis[i]+lds[i]);
		}
		printf("%d\n", mvalue-1);

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