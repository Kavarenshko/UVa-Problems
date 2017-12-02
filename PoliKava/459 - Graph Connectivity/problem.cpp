#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int ALPHA = 26;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

graph g;
bool visited[ALPHA];

void walk(int n)
{
	visited[n] = true;
	for(auto &nbr : g[n])
	{
		if (!visited[nbr])
			walk(nbr);
	}
}

int main()
{
	int TC;
	char mc;
	scanf("%d", &TC);

	getchar();
	string skip;
	getline(cin, skip);
	FOR(tc, TC)
	{
		g.assign(ALPHA, vi());
		FOR(i,ALPHA)
			visited[i] = false;

		while(1)
		{
			string s;
			getline(cin, s);

			if (s.size() == 0)
				break;
			else if (s.size() == 1)
				mc = s[0];
			else if (s.size() == 2)
			{
				char n1,n2;
				n1 = s[0];
				n2 = s[1];
				print("\nNew edge: %c-%c", n1,n2);
				g[n1-'A'].push_back(n2-'A');
				g[n2-'A'].push_back(n1-'A');
			}
			else
			{
				print("OEILA");
				*(int*)0 = 0;
			}
		}

		for(int i=0; i <= (mc-'A'); i++)
			g[i].push_back(i);

		int count = 0;
		for(int i=0; i < ALPHA; i++)
		{
			if (g[i].size() > 0 && !visited[i])
			{
				walk(i);
				count += 1;
			}
		}

		if (tc)
			printf("\n");
		printf("%d\n", count);
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