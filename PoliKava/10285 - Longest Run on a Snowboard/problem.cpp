#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 100;
constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int R, C, m[MAX][MAX], dp[MAX][MAX];

int walk(int rx, int cx)
{
	if (dp[rx][cx] != INF)
		return dp[rx][cx];

	int mpath = 1;
	if (rx - 1 >= 0 && m[rx-1][cx] < m[rx][cx])
		mpath = max(mpath, walk(rx-1,cx)+1);
	if (rx + 1 < R && m[rx+1][cx] < m[rx][cx])
		mpath = max(mpath, walk(rx+1,cx)+1);
	if (cx - 1 >= 0 && m[rx][cx-1] < m[rx][cx])
		mpath = max(mpath, walk(rx,cx-1)+1);
	if (cx + 1 < C && m[rx][cx+1] < m[rx][cx])
		mpath = max(mpath, walk(rx,cx+1)+1);
	return dp[rx][cx] = mpath;
}

int main()
{
	int N;

	scanf("%d", &N);

	FOR(tc, N)
	{
		string n;

		cin >> n >> R >> C;
		FOR(i, R)
		{
			FOR(j, C)
			{
				scanf("%d", &m[i][j]);
				dp[i][j] = INF;
			}
		}

		int mvalue = 0;
		FOR(i, R)
		{
			FOR(j, C)
			{
				if (dp[i][j] == INF)
					walk(i,j);
				mvalue = max(mvalue, dp[i][j]);
			}
		}

		printf("%s: %d\n", n.c_str(), mvalue);
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