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

int p,q,r,s,t,u;

double valueExp(double x)
{
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2.0) + u;
}

double roundAlpha(double x)
{
	return x;//floor(x * 10000 + 0.5) / 10000.0;
}

int main()
{
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6)
	{
		int count = 0;
		double lo, hi;

		lo = 0.0000;
		hi = 1.0000;

		print("\n\nTEST CASE - - - - - - -\n\n");

		while(1)
		{
			double res = valueExp( (lo+hi) / 2.0 );
			print("\nCurrent x = %.5lf, res is %.5lf", (lo+hi) / 2.0, res);
			if (fabs(res) <= 0.0000000009)
			{
				printf("%.4lf\n", (lo+hi)/2.0);
				break;
			}
			else
			{
				if (res > 0.0)
					lo = (lo+hi)/2.0;
				else
					hi = (lo+hi)/2.0;
			}

			count += 1;
			if (count == 100)
			{
				printf("No solution\n");
				break;
			}
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