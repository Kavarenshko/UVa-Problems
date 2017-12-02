#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int CHESSBOARD_SIZE = 8;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int m[CHESSBOARD_SIZE][CHESSBOARD_SIZE], maxScore;
int queens[CHESSBOARD_SIZE]; // store row

bool place(int r, int c)
{
	for (int prev = 0; prev < c; prev++)
		if (queens[prev] == r || (abs(queens[prev] - r) == abs(prev - c)))
			return false;
	return true;
}

void walk(int col, int score)
{
	if (col == CHESSBOARD_SIZE)
	{
		maxScore = max(score, maxScore);
		return;
	}

	// select row
	for(int i=0; i < CHESSBOARD_SIZE; i++)
	{
		if (place(i, col)) // if feasible
		{
			queens[col] = i;
			walk(col+1, score + m[i][col]);
		}
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		maxScore = 0;
		FOR(i, CHESSBOARD_SIZE)
			FOR(j, CHESSBOARD_SIZE)
				scanf("%d", &m[i][j]);
		walk(0, 0);
		printf("%5d\n", maxScore);
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