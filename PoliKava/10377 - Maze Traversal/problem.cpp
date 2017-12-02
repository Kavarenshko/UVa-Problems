#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int LIMIT = 61;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int R,C,cx,cy,cd;
bool m[LIMIT][LIMIT];

bool isValid(int r, int c)
{
	if (r < 1 || c < 1 || r > R || c > C || !m[r][c])
		return false;
	return true;
}

char intToDir(int i)
{
	if (i == 0)
		return 'N';
	else if (i == 1)
		return 'W';
	else if (i == 2)
		return 'S';
	else
		return 'E';
}

int dirToChar(int c)
{
	if (c == 'N')
		return 0;
	else if (c == 'W')
		return 1;
	else if (c == 'S')
		return 2;
	else
		return 3;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	int ar[] = {-1,0,1,0};
	int ac[] = {0,-1,0,1};

	FOR(tc, TC)
	{
		scanf("%d %d", &R, &C);
		getchar();

		FOR1(i, R)
		{
			FOR1(j, C)
			{
				char c = getchar();
				m[i][j] = (c == ' ');
			}
			getchar();
		}

		cd = 0;
		scanf("%d %d", &cx, &cy);
		while(1)
		{
			char c = getchar();

			if (c == 'Q')
				break;
			else if (c == 'F')
			{
				if (isValid(cx+ar[cd], cy+ac[cd]))
				{
					cx += ar[cd];
					cy += ac[cd];
				}
			}
			else if (c == 'R')
			{
				cd -= 1;
				if (cd < 0)
					cd = 3;
			}
			else if (c == 'L')
			{
				cd += 1;
				if (cd > 3)
					cd = 0;
			}
			else
				continue;
			print("\nCommand %c: pos %d %d %c", c, cx, cy, intToDir(cd));
		}

		if (tc)
			printf("\n");
		printf("%d %d %c\n", cx, cy, intToDir(cd));
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