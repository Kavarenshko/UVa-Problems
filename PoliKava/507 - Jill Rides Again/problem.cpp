#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int main()
{
	int TC;
	vi v, ccount;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		int S;
		bool bad = true;
		scanf("%d", &S);

		v.clear();
		ccount.clear();

		FOR(i, S-1)
		{
			int n;
			scanf("%d", &n);
			if (n > 0)
				bad = false;
			v.push_back(n);
			ccount.push_back(0);
		}
		v.push_back(-INF);

		if (bad)
			printf("Route %d has no nice parts\n", tc);
		else
		{

			for(int i=S-2; i >= 0; i--)
			{
				if (v[i+1] >= 0)
				{
					v[i] += v[i+1];
					ccount[i] = ccount[i+1] + 1;
				}
			}
			int mvalue = -INF, mindex = -INF, mcount = -INF;
			for(int i=0; i < S-1; i++)
			{
				if (v[i] > mvalue)
				{
					mvalue = v[i];
					mindex = i;
					mcount = ccount[i];
				}
				else if (v[i] == mvalue)
				{
					if (ccount[i] > mcount)
					{
						mcount = ccount[i];
						mindex = i;
					}
				}
			}

			printf("The nicest part of route %d is between stops %d and %d\n", tc, mindex+1, mindex+1+mcount+1);
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