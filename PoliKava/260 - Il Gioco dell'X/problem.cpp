#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 201;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N;
bool m[MAX][MAX];
bool v[MAX][MAX];
bool black;

bool isValid(int r, int c)
{
	if (r < 0 || c < 0 || r >= N || c >= N)
		return false;
	return m[r][c];
}

void walk(int r, int c)
{
	int ar[] = {-1,-1,0,0,1,1};
	int ac[] = {-1,0,-1,1,0,1};

	if (r == N-1)
	{
		black = true;
		return;
	}

	v[r][c] = true;
	for(int i=0; i < 6; i++)
	{
		if (isValid(r+ar[i], c+ac[i]))
		{
			if (!v[r+ar[i]][c+ac[i]])
				walk(r+ar[i], c+ac[i]);
		}
	}
}

int main()
{
	FOR1(tc, INF)
	{
		scanf("%d", &N);
		if (!N)
			break;

		black = false;
		FOR(i,N)
		{
			getchar();
			FOR(j,N)
			{
				char c = getchar();
				m[i][j] = (c == 'b');
				v[i][j] = false;
			}
		}

		FOR(j,N)
		{
			if (m[0][j] && !v[0][j])
				walk(0,j);
		}
		printf("%d %c\n", tc, (black)? 'B' : 'W');
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