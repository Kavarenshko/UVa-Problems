#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX = 100;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N;
bool v[MAX];

int main()
{
	int TC, tot;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		scanf("%d", &N);
		printf("Case %d: ", tc);

		tot = 0;

		getchar();
		FOR(i, N)
		{
			char c = getchar();
			if (c == '.')
				v[i] = true;
			else if (c == '#')
				v[i] = false;
			else
				*(int*)0 = 0;
		}

		bool trigger = false;
		for(int i=0; i < N; i++)
		{
			//print("\nAnalyzing index %d, which is %s.", i, (v[i]? "true" : "false"));
			if (trigger)
			{
				tot += 1;
				i++;
				trigger = false;
			}
			else
			{
				if (v[i])
					trigger = true;
			}
		}
		if (trigger)
			tot += 1;
		printf("%d\n", tot);
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