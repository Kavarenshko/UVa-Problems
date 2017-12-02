#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

void printSolution(int SZ, llu r, llu c)
{
	printf("Line = %llu, column = %llu.\n", SZ-r, c+1);
}

ii getUpperCoords(int SZ, int odd)
{
	int r,c;

	r = SZ/2 - 1;
	c = SZ/2;
	odd -= 2;

	while(odd > 1)
	{
		r--;
		c++;
		odd -= 2;
	}
	return {r,c};
}

int main()
{
	int oeila = 0;
	while(1)
	{
		int SZ;
		llu P;
		scanf("%d %llu", &SZ, &P);

		if (!SZ && !P)
			break;

		if (P == 1)
		{
			printSolution(SZ, SZ/2, SZ/2);
			continue;
		}

		int odd = 3;
		llu prev = 1;
		bool done = false;
		
		while(1)
		{
			print("\nCurrent prev %llu, odd %d.", prev, odd);

			if (P > prev && P <= (prev + (2*odd + 2*(odd-2))))
			{
				print("\nNumber %llu appears to be in range %llu-%llu, with odd = %d.", P, prev+1, (prev + (2*odd + 2*(odd-2))), odd);
				ii c = getUpperCoords(SZ, odd);
				print("\n  > starting coords: (%d, %d)", c.first, c.second);
				llu start = prev+1;

				print("\n  > *1* ");

				for(int i=0; i < (odd-1); i++)
				{
					if (start + i == P)
					{
						printSolution(SZ, c.first, c.second-i);
						done = true;
						break;
					}
				}

				if (done)
					break;

				print("*2* ");

				c.second -= odd-2;
				start += odd-2;
				for(int i=0; i < odd; i++)
				{
					if (start + i == P)
					{
						printSolution(SZ, c.first+i, c.second);
						done = true;
						break;
					}
				}

				if (done)
					break;

				print("*3* ");

				c.first += odd-1;
				start += odd-1;
				for(int i=0; i < odd; i++)
				{
					if (start + i == P)
					{
						printSolution(SZ, c.first, c.second+i);
						done = true;
						break;
					}
				}

				if (done)
					break;

				print("*4*");

				c.second += odd-1;
				start += odd-1;
				for(int i=0; i < odd; i++)
				{
					if (start + i == P)
					{
						printSolution(SZ, c.first-i, c.second);
						done = true;
						break;
					}
				}

				if (done)
					break;
				*(int*)0 = 0;
			}
			else
			{
				prev += (2*odd + 2*(odd-2));
				odd += 2;
			}
		}
		oeila++;
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