#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 101;
constexpr int INF = 100000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int main()
{
	int a[MAX][MAX];

	FOR1(tc, INF)
	{
		//print("\n\nTEST CASE\n\n");
		for(int i=1; i < MAX; i++)
			for(int j=1; j < MAX; j++)
				a[i][j] = INF;

		int ecount = 0;
		for(int i=0;;i++)
		{
			int A,B;
			scanf("%d %d", &A, &B);

			if (!A && !B)
				break;

			a[A][B] = 1;
			ecount += 1;
		}

		if (!ecount)
			break;

		/*for(int i=1; i < MAX; i++)
			for(int j=1; j < MAX; j++)
				print("\na[%d][%d] = %d", i, j, a[i][j]);
		print("\n\n\n");*/

		for(int k=1; k < MAX; k++)
			for(int s=1; s < MAX; s++)
				for(int t=1; t < MAX; t++)
					a[s][t] = min(a[s][t], a[s][k] + a[k][t]);

		/*(i, MAX-1)
			FOR1(j, MAX-1)
				print("\na[%d][%d] = %d", i, j, a[i][j]);*/

		ecount = 0;
		double s = 0.0;
		for(int i=1; i < MAX; i++)
		{
			for(int j=1; j < MAX; j++)
			{
				if (i == j || a[i][j] < 0 || a[i][j] > MAX)
					continue;
				//print("\na[%d][%d] = %d", i, j, a[i][j]);
				s += a[i][j];
				ecount += 1;
			}
		}
		//print("\nFINAL COUNT = %.3lf", s);
		s /= ecount;
		printf("Case %d: average length between pages = %.3lf clicks\n", tc, s);
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