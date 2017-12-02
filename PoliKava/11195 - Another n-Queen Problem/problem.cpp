#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 15;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N;
ll mvalue;
vi m;
vi placed;

map< vi, ll > dp;

void walk(int row, int ld, int rd, int col)
{
	int full = (1 << N)-1;

	if (row == full)
	{
		mvalue += 1;
		return;
	}

	int free_spaces = full & (~(row | ld | rd));
	while(free_spaces)
	{
		int lsb = free_spaces & -free_spaces;
		free_spaces -= lsb; // remove lsb

		if (m[col] & lsb)
		{
			//print("\nHole skipped at col %d and row %d", col, lsb);
			continue;
		}
		walk(row | lsb, (ld | lsb) << 1, (rd | lsb) >> 1, col+1);
	}
}

int main()
{
	FOR1(tc, INF)
	{
		scanf("%d", &N);
		if (!N)
			break;

		mvalue = 0;
		dp.clear();
		m.assign(N, 0);
		FOR(i,N)
		{
			getchar();
			FOR(j,N)
			{
				char c = getchar();
				if (c != '.')
					m[j] |= (1 << i);
			}
		}

		/*
		print("\n\n");
		for(auto &el : m)
			print("> %d\n", el);
		*/

		walk(0,0,0,0);
		printf("Case %d: %lld\n", tc, mvalue);
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