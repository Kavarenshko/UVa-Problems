#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX_MATRIX = 500;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N,M,Q;
graph v;

int main()
{
	while(1)
	{
		scanf("%d %d", &N, &M);
		if(!N && !M)
			break;

		v.assign(N, vi());
		FOR(i, N)
		{
			v[i].assign(M, 0);
			FOR(j, M)
				scanf("%d", &v[i][j]);
		}

		scanf("%d", &Q);
		FOR(query, Q)
		{
			int L,U, curr_max = -1;
			scanf("%d %d", &L, &U);

			FOR(i, N) // for every row
			{
				//print("\nAnalyzing row %d...", i);
				auto it = lower_bound(v[i].begin(), v[i].end(), L);

				if (it == v[i].end() || *it > U) // not found, skip this row
					continue;

				curr_max = max(curr_max, 0);
				int ind = it - v[i].begin();

				for(int k = curr_max+1; k < MAX_MATRIX; k++)
				{
					if (i + k >= N || ind + k >= M)
						break;
					if (v[i + k][ind+k] > U)
						break;
					curr_max = max(curr_max, k);
				}
			}
			printf("%d\n", curr_max+1);
		}
		printf("-\n");
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