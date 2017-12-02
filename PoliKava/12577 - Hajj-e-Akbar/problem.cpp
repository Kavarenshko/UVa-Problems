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

int main()
{
	string current;
	FOR1(tc, INF)
	{
		getline(cin, current);
		if (current[0] == '*')
			break;
		else if (current[0] == 'H')
			printf("Case %d: Hajj-e-Akbar\n", tc);
		else if (current[0] == 'U')
			printf("Case %d: Hajj-e-Asghar\n", tc);
		else
			*(int*)0 = 0;
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