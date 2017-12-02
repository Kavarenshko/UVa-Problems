#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int LIMIT = 10001;
constexpr int VOID = 0;
constexpr int MULTIPLE = 4;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int a[LIMIT];
vi v1,v2,v3;

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		printf("Case #%d:\n", tc);

		FOR(i, LIMIT)
			a[i] = VOID;
		v1.clear();
		v2.clear();
		v3.clear();

		for(int i=1; i <= 3; i++)
		{
			int K;
			scanf("%d", &K);
			FOR(j, K)
			{
				int c;
				scanf("%d", &c);
				if (a[c] == VOID)
					a[c] = i;
				else if (a[c] >= 1 && a[c] <= 3)
					a[c] = MULTIPLE;
				else // already MULTIPLE
					continue;
			}
		}

		int p1,p2,p3,m;
		p1 = p2 = p3 = 0;
		FOR(i, LIMIT)
		{
			if (a[i] == 1)
			{
				p1 += 1;
				v1.push_back(i);
			}
			else if (a[i] == 2)
			{
				p2 += 1;
				v2.push_back(i);
			}
			else if (a[i] == 3)
			{
				p3 += 1;
				v3.push_back(i);
			}
		}
		m = max(p1, max(p2,p3));

		if (p1 == m)
		{
			printf("1 %lu", v1.size());
			for(auto &nn : v1)
				printf(" %d", nn);
			printf("\n");
		}
		if (p2 == m)
		{
			printf("2 %lu", v2.size());
			for(auto &nn : v2)
				printf(" %d", nn);
			printf("\n");
		}
		if (p3 == m)
		{
			printf("3 %lu", v3.size());
			for(auto &nn : v3)
				printf(" %d", nn);
			printf("\n");
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