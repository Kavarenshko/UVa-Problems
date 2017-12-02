#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 101;
constexpr int INF = 1000000000;
constexpr int UNVISITED = -1;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N,R,C,solutions,dp[MAX][MAX];
bool m[MAX][MAX];

llu walk(int r, int c)
{
	if (dp[r][c] != UNVISITED)
		return dp[r][c];

	if (r == 0)
		return dp[r][c] = 1;

	llu tot_sol = 0;

	if (c - 1 >= 0) // valid pos
	{
		if (m[r-1][c-1])
			tot_sol += walk(r-1, c-1) % 1000007;
		else
		{
			if (r-2 >= 0 && c-2 >= 0 && m[r-2][c-2])
				tot_sol += walk(r-2, c-2) % 1000007;
		}
	}

	if (c + 1 < N) // valid pos
	{
		if (m[r-1][c+1])
			tot_sol += walk(r-1, c+1) % 1000007;
		else
		{
			if (r-2 >= 0 && c+2 < N && m[r-2][c+2])
				tot_sol += walk(r-2, c+2) % 1000007;
		}
	}
	return dp[r][c] = tot_sol % 1000007;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		printf("Case %d: ", tc);
		scanf("%d", &N); getchar();

		solutions = 0;
		FOR(i, MAX)
			FOR(j, MAX)
				dp[i][j] = UNVISITED;

		FOR(i, N)
		{
			FOR(j, N)
			{
				char c = getchar();
				if (c == '.')
					m[i][j] = true;
				else if (c == 'B')
					m[i][j] = false;
				else if (c == 'W')
				{
					R = i;
					C = j;
				}
				else
					*(int*)0 = 0;
				print("%c ", m[i][j]? '1' : '0');
			}
			getchar();
			print("\n");
		}
		printf("%llu\n", walk(R,C));
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