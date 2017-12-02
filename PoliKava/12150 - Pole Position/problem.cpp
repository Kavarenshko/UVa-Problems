#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int LIMIT = 1002;
constexpr int VOID = 0;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int a[LIMIT];

int main()
{
	while(1)
	{
		int N;
		scanf("%d", &N);

		if (!N)
			break;

		FOR(i, LIMIT)
			a[i] = VOID;

		bool possible = true;
		FOR1(i, N)
		{
			int C,P;
			scanf("%d %d", &C, &P);

			if (i+P < 1 || i+P > N)
				possible = false;
			if (a[i+P] != VOID)
				possible = false;
			if (possible)
				a[i+P] = C;
		}

		if (!possible)
		{
			printf("-1\n");
			continue;
		}

		for(int i=1; i < N; i++)
			printf("%d ", a[i]);
		printf("%d\n", a[N]);
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