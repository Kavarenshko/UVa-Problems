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
	vi v;
	vector< pair<int, ii> > lis;
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int N;
		
		scanf("%d", &N);
		v.clear();
		lis.clear();

		FOR(i, N)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
			lis.push_back({0, {0,0}});
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

		lis[0] = {1, {v[0], v[0]}};
		int tot = -1;
		for(int i=1; i < N; i++)
		{
			print("\n\nAnalyzing element %d...", i);
			int mvalue = -1, mindex = -1;
			bool onMax = false;
			for(int j=i-1; j >= 0; j--)
			{
				print("\n  > comparing with index %d (best = %d | (%d,%d))", j, lis[j].first, lis[j].second.first, lis[j].second.second);
				if (v[i] > lis[j].second.first) // put on front
				{
					print("\n    > can put on front");
					if (lis[j].first > mvalue)
					{
						mvalue = lis[j].first;
						mindex = j;
						onMax = true;
						print(", new max is %d", mvalue);
					}
					else if (lis[j].first == mvalue)
					{
						if (lis[j].second.second > lis[mindex].second.second)
						{
							mvalue = lis[j].first;
							mindex = j;
							onMax = true;
							print(", adjusted max with better solution");
						}
					}
				}
				else if (v[i] < lis[j].second.second)
				{
					print("\n    > can push back");
					if (lis[j].first > mvalue)
					{
						mvalue = lis[j].first;
						mindex = j;
						print(", new max is %d", mvalue);
					}
					else if (lis[j].first == mvalue)
					{
						if (lis[j].second.first < lis[mindex].second.first)
						{
							mvalue = lis[j].first;
							mindex = j;
							print(", adjusted max with better solution");
						}
					}
				}
			}

			if (onMax)
				lis[i] = {mvalue+1, {v[i], lis[mindex].second.second}};
			else
				lis[i] = {mvalue+1, {lis[mindex].second.first, v[i]}};
			tot = max(tot, lis[i].first);
			print("\nLIS[%d] = %d | (%d, %d)", i, lis[i].first, lis[i].second.first, lis[i].second.second);
		}
		if (tot == -1)
			*(int*)0 = 0;
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