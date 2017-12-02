#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int S = 8;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

int R,C,sol;
bool m[S][S];
vector<int> v;

void print(const char* msg, ...);

bool isValid(int r, int c)
{
	FOR(i, S) // check if row is free
	{
		if (i == c)
			continue;
		if (m[r][i])
			return false;
	}

	int f = min(r,c);
	while(1)
	{
		if (r-f >= S || c-f >= S)
			break;
		if (!f)
		{
			f -= 1;
			continue;
		}
		if (m[r-f][c-f])
			return false;
		f -= 1;
	}

	for(int i=1;;i++)
	{
		if (r-i < 0)
			break;
		if (c+i >= S)
			break;
		if (m[r-i][c+i])
			return false;
	}

	for(int i=1;;i++)
	{
		if (r+i >= S)
			break;
		if (c-i < 0)
			break;
		if (m[r+i][c-i])
			return false;
	}
	return true;
}

void printSolution()
{
	if (sol < 10)
		printf("\n %d      ", sol);
	else
		printf("\n%d      ", sol);
	sol += 1;
	for(unsigned i=0; i < v.size()-1; i++)
		printf("%d ", v[i]+1);
	printf("%d", v.back()+1);
}

void walk(int col)
{
	/*print("\n");
	for(auto &el : v)
		print("%d ", el);
	print("\nAnalyzing column %d...", col);*/

	if (col == S)
	{
		//print("printing solution.");
		printSolution();
		return;
	}

	if (col == C-1) // input-defined queen
	{
		//print("USER DEFINED QUEEN AT (%d,%d), ", R-1, col);
		if (col == S-1) // OK solution
		{
			//print("ok solution");
			v.push_back(R-1);
			printSolution();
			v.pop_back();
		}
		else
		{
			//print("continuing solution");
			v.push_back(R-1);
			walk(col+1);
			v.pop_back();
		}
		return;
	}

	for(int i=0; i < S; i++)
	{
		if (isValid(i,col))
		{
			//print("\n  > (col %d) row %d seems a valid solution", col, i);
			v.push_back(i);
			m[i][col] = true;
			walk(col+1);
			m[i][col] = false;
			v.pop_back();
		}
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		scanf("%d %d", &R, &C);

		FOR(i, S)
			FOR(j, S)
				m[i][j] = false;

		m[R-1][C-1] = true;
		sol = 1;

		if (tc)
			printf("\n\n");
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");

		walk(0);
	}
	printf("\n");

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