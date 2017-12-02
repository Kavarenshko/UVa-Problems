#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 50;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N,L;
int dp[MAX][MAX][MAX];
int s_x, s_y;
int a[MAX][MAX];

bool isValid(int x, int y)
{
	if (x >= 0 && y >= 0 && x < N && y < N)
		return true;
	return false;
}

int walk(int x, int y, int rem)
{
	print("\nAnalyzing (%d,%d,%d) with val = %d, ", x, y, rem, a[x][y]);

	if (dp[x][y][rem] != -1)
	{
		print("already calculated");
		return dp[x][y][rem];
	}

	if (!isValid(x,y))
	{
		print("not valid");
		return -INF; // max(nbrs)
	}
	if (rem == 0)
	{
		print("last, returning %d", a[x][y]);
		return a[x][y];
	}

	int mvalue = -1;

	// upper left
	FOR1(i, INF)
	{
		if (isValid(x-i, y-i))
			mvalue = max(mvalue, walk(x-i, y-i, rem-1));
		else
			break;
	}

	// upper right
	FOR1(i, INF)
	{
		if (isValid(x-i, y+i))
			mvalue = max(mvalue, walk(x-i, y+i, rem-1));
		else
			break;
	}

	// lower left
	FOR1(i, INF)
	{
		if (isValid(x+i, y-i))
			mvalue = max(mvalue, walk(x+i, y-i, rem-1));
		else
			break;
	}

	// lower right
	FOR1(i, INF)
	{
		if (isValid(x+i, y+i))
			mvalue = max(mvalue, walk(x+i, y+i, rem-1));
		else
			break;
	}

	print("\nFinal value for (%d,%d,%d) is %d", x,y,rem, mvalue + a[x][y]);

	return dp[x][y][rem] = mvalue + a[x][y];
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		FOR(i, MAX)
		{
			FOR(j, MAX)
			{
				FOR(k, MAX)
				{
					dp[i][j][k] = -1;
					a[j][k] = INF;
				}
			}
		}

		scanf("%d %d %d %d", &N, &L, &s_y, &s_x);
		FOR(i, N)
		{
			FOR(j, N)
			{
				scanf("%d", &a[i][j]);
				//print("%d ", a[i][j]);
			}
			//print("\n");
		}
		printf("%d\n", walk(s_x, s_y, L)-a[s_x][s_y]);
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