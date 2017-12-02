#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX_DIMS = 1100;
constexpr int MAX_DISHES = 22;
constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N,X,T,K,W[MAX_DIMS],V[MAX_DIMS],dp[MAX_DIMS][MAX_DIMS][MAX_DISHES];

inline bool isOver(int w) { return ( ceil( (double)(w+T*(N+1)) * 1.1L) > X*(N+1) ); }

int walk(int ind, int w, int dim_count)
{
	//if (isOver(w))
	//print("\n(%d,%d) - Weight %d is over (%d + %d + %.2lf = %.2lf) and X is %d", ind, dim_count, w, w, T*(N+1), 0.1*(w + T*(N+1)), (w + T*(N+1) + 0.1*(w + T*(N+1))), X*(N+1));

	if (isOver(w) || dim_count > (2*(N+1)))
		return -INF;
	if (ind == K+1 || ceil( (double)(w+T*(N+1)) * 1.1L) == X*(N+1) || dim_count == (2*(N+1)))
		return 0;
	if (dp[ind][w][dim_count] != -1)
		return dp[ind][w][dim_count];
	/*if (isOver(w+W[ind]) || dim_count + 1 > (2*(N+1)))
		return dp[ind][w][dim_count] = walk(ind+1, w, dim_count);
	if (isOver(w+2*W[ind]) || dim_count + 2 > (2*(N+1)))
		return dp[ind][w][dim_count] = max(walk(ind+1, w, dim_count), V[ind] + walk(ind+1, w + W[ind], dim_count + 1));
	*/
	int take0, take1, take2;

	take0 = walk(ind+1, w, dim_count);
	take1 =   V[ind] + walk(ind+1, w + W[ind], dim_count + 1);
	take2 = 2*V[ind] + walk(ind+1, w + 2*W[ind], dim_count + 2);

	return dp[ind][w][dim_count] = max(take0, max(take1, take2));
}

int main()
{
	FOR1(tc, INF)
	{
		scanf("%d %d %d %d", &N, &X, &T, &K);
		if (!N && !X && !T && !K)
			break;

		FOR(i, MAX_DIMS)
		{
			V[i] = W[i] = 0;
			FOR(j, MAX_DIMS)
			{
				FOR(k, MAX_DISHES)
					dp[i][j][k] = -1;
			}
		}

		FOR(i, K)
		{
			int res;
			scanf("%d", &W[i]);
			FOR(j, N+1)
			{
				scanf("%d", &res);
				V[i] += res;
			}
		}
		/*if (tc != 10)
			continue;*/
		int mvalue = walk(0, 0, 0);
		printf("%.2lf\n", (double)(mvalue) / (double)(N+1));
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