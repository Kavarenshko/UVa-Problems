#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 20;
constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int R,C,x,y,max_continent;
bool m[MAX][MAX];
char f[MAX][MAX];
bool visited[MAX][MAX];

int walk(int cx, int cy)
{
	//print("\nCell (%d,%d)", cx, cy);
	int tot = 1; // self
	visited[cx][cy] = true;
	for(int i=-1; i <= 1; i++)
	{
		for(int j=-1; j <= 1; j++)
		{
			//print("\n  > (%d,%d) - %d %d", cx, cy, i, j);
			if (abs(i) + abs(j) == 2)
				continue;
			if (cx + i >= 0 && cx + i < R) // valid pos
			{
				if (cy+j < 0)
				{
					if (m[cx+i][C-1] && !visited[cx+i][C-1])
						tot += walk(cx+i, C-1);
				}
				else if (cy+j >= C)
				{
					if (m[cx+i][0] && !visited[cx+i][0])
						tot += walk(cx+i, 0);
				}
				else
				{
					if (m[cx+i][cy+j] && !visited[cx+i][cy+j]) // if unvisited land
						tot += walk(cx+i,cy+j);
				}
			}
		}
	}
	return tot;
}

int main()
{
	char target;
	while(scanf("%d %d", &R, &C) == 2)
	{
		getchar();
		max_continent = 0;
		FOR(i,R)
		{
			FOR(j,C)
			{
				char c = getchar();
				f[i][j] = c;
				visited[i][j] = false;
			}
			getchar();
		}
		scanf("%d %d", &x, &y);
		target = f[x][y];
		FOR(i,R)
		{
			FOR(j,C)
			{
				m[i][j] = (f[i][j] == target);
			}
		}
		//print("\nFirst run: %d", walk(x,y)); // discard this solution
		walk(x,y);
		FOR(i,R)
		{
			FOR(j,C)
			{
				if (m[i][j] && !visited[i][j])
				{
					max_continent = max(max_continent, walk(i,j));
					//print("\n***\n");
				}
			}
		}
		printf("%d\n", max_continent);
		//break;
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