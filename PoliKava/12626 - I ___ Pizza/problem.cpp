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

int alpha[26];

int main()
{
	int TC;
	string m = "MARGARITA";

	scanf("%d", &TC);
	getchar();

	FOR1(tc, TC)
	{
		int tot = 0;
		string cline;

		getline(cin, cline);

		for(int i=0; i < 26; i++)
			alpha[i] = 0;

		for(auto &c : cline)
			alpha[c - 'A'] += 1;

		bool possible = true;
		while(1)
		{
			for(auto &c : m)
			{
				if (alpha[c - 'A'] == 0)
				{
					possible = false;
					break;
				}
				alpha[c - 'A'] -= 1;
			}
			if (!possible)
				break;
			tot += 1;
		}
		printf("%d\n", tot);
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