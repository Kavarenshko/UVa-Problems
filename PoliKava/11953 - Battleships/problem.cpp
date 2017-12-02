#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int EMPTY = 0;
constexpr int SHIP = 1;
constexpr int HIT = 2;
constexpr int LIMIT = 101;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N;
int m[LIMIT][LIMIT];

bool isValid(int r, int c)
{
	if (r < 0 || c < 0 || r >= N || c >= N)
		return false;
	return true;
}

int walk(int r, int c)
{
	int ar[] = {-1,0,1,0};
	int ac[] = {0,-1,0,1};

	m[r][c] = EMPTY;
	for(int i=0; i < 4; i++)
	{
		if (!isValid(r+ar[i], c+ac[i]))
			continue;

		if (m[r+ar[i]][c+ac[i]] == SHIP || m[r+ar[i]][c+ac[i]] == HIT)
		{
			walk(r+ar[i], c+ac[i]);
		}
	}
	return 1;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		scanf("%d", &N);
		getchar();

		FOR(i,N)
		{
			FOR(j,N)
			{
				char c = getchar();
				if (c == '.')
					m[i][j] = EMPTY;
				else if (c == 'x')
					m[i][j] = SHIP;
				else if (c == '@')
					m[i][j] = HIT;
				else
					*(int*)0 = 0;
			}
			getchar();
		}

		int tot = 0;
		FOR(i,N)
		{
			FOR(j,N)
			{
				if (m[i][j] == SHIP)
					tot += walk(i,j);
			}
		}
		printf("Case %d: %d\n", tc, tot);
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