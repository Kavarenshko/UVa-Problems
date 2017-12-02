#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

long long S,D;
long long maxSurplus, currSurplus;
long long v[12];

bool walk(int month)
{
	if (month == 12)
	{
		currSurplus = 0;
		for(int i=0; i < 12; i++)
			currSurplus += v[i];
		if (currSurplus < 0)
			return false;
		maxSurplus = max(maxSurplus, currSurplus);
		return true;
	}

	if (month < 4)
	{
		v[month] = S;
		if (walk(month+1))
			return true;
		v[month] = D;
		if (walk(month+1))
			return true;
	}
	else
	{
		long long csum = 0;
		for(int i=month-4; i < month; i++)
			csum += v[i];

		if (csum + D >= 0)
			return false;

		if (csum + S < 0) // still deficit, can continue
		{
			v[month] = S;
			if (walk(month+1))
				return true;
		}
		v[month] = D;
		if (walk(month+1))
			return true;
	}

	return false;	
}

int main()
{
	while(1)
	{
		if (scanf("%lld %lld", &S, &D) != 2)
			break;

		D *= -1;
		maxSurplus = -1;

		if (walk(0))
			printf("%lld\n", maxSurplus);
		else
			printf("Deficit\n");
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