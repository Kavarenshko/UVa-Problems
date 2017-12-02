#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

typedef pair<int, ii> coord;

void print(const char* msg, ...);

bool compareElements(coord a, coord b)
{
	if (a.second.first < b.second.first)
		return true;
	else if (a.second.first > b.second.first)
		return false;

	// same row

	if (a.second.second < b.second.second)
		return true;
	return false;
}

int main()
{
	int M,N;

	while(scanf("%d %d", &M, &N) == 2)
	{

		print("\n\nTEST CASE - - - - - - -\n\n");

		int R;
		vi v;
		vector<coord> t;

		FOR(i, M) // for every row
		{
			scanf("%d", &R); // number of non-zero elements in that row
			v.assign(R, -1);
			FOR(j, R)
				scanf("%d", &v[j]); // store index of j-th non-zero element
			FOR(j, R)
			{
				coord element;
				scanf("%d", &element.first);
				element.second = {v[j], i};
				t.push_back(element);
			}
		}
		sort(t.begin(), t.end(), compareElements);
		for(auto &el : t)
		{
			print("\n  > (%d,%d) : %d", el.second.first, el.second.second, el.first);
		}
		//return 0;
		printf("%d %d\n", N, M);
		int start = 0;
		FOR1(i, N)
		{
			print("\nAnalyzing row %d...", i);
			vector<ii> k;
			for(unsigned j=start; j < t.size(); j++)
			{
				print("\n  > (%d,%d) : %d", t[j].second.first, t[j].second.second, t[j].first);
				if (t[j].second.first != i) // different row
				{
					print(", break");
					start = j;
					break;
				}
				k.push_back({t[j].second.second, t[j].first});
			}

			if (k.size() == 0)
			{
				printf("0\n\n");
				continue;
			}
			
			printf("%lu", k.size());
			for(unsigned j=0; j < k.size(); j++)
				printf(" %d", k[j].first+1);
			printf("\n");
			for(unsigned j=0; j < (k.size()-1); j++)
				printf("%d ", k[j].second);
			printf("%d\n", k.back().second);
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