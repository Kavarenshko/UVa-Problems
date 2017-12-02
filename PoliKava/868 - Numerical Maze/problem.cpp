#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int R,C;
int s_cell, e_cell;
vector< vector<ll> > v;

inline bool isValid(int r, int c) { return (r >= 0 && c >= 0 && r < R && c < C); }

bool walk(int r, int c, ll top, ll val)
{
	//print("\nAnalyzing coord (%d,%d) with top %u and val %u", r,c,top,val);
	if (r == R-1) // reached the end
	{
		e_cell = min(e_cell, c+1);
		return true;
	}

	int ar[] = {-1,0,1,0};
	int ac[] = {0,-1,0,1};

	bool foundSol = false;
	for(int i=0; i < 4; i++)
	{
		//print("\n  > isValid(%d,%d)? ", r+ar[i], c+ac[i]);
		if (isValid(r+ar[i], c+ac[i]))
		{
			//print("YES");
			if (val == top)
			{
				if (v[r+ar[i]][c+ac[i]] == 1LL)
				{
					if (walk(r+ar[i], c+ac[i], top+1, 1))
						foundSol = true;
				}
			}
			else
			{
				if (v[r+ar[i]][c+ac[i]] == val+1)
				{
					if (walk(r+ar[i], c+ac[i], top, val+1))
						foundSol = true;
				}
			}
		}
	}
	return foundSol;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		scanf("%d %d", &R, &C);

		if (tc)
			printf("\n");

		v.clear();
		v.assign(R, vector<ll>());
		for(auto &vv : v)
			vv.assign(C, 0);
		s_cell = e_cell = INF;

		FOR(i, R)
			FOR(j, C)
				scanf("%lld", &v[i][j]);

		for(int i=0; i < C; i++) // search starting point
		{
			if (v[0][i] == 1 && walk(0, i, 1, 1))
			{
				s_cell = i+1;
				break;
			}
			//print("\n\n\n\n\n\n");
		}

		if (s_cell == INF || e_cell == INF)
			*(int*)0 = 0;

		printf("1 %d\n%d %d\n", s_cell, R, e_cell);
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