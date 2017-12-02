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
bool v[ALPHA];
int incoming[ALPHA],tnodes;
set<string> s;

void walk(int n, string curr)
{
	curr += 'a'+n;

	if ((int)curr.size() == tnodes)
	{
		reverse(curr.begin(),curr.end());
		s.insert(curr);
		return;
	}

	v[n] = true;
	for(auto &nbr : g[n])
		incoming[nbr] -= 1;

	for(int i=0; i < ALPHA; i++)
	{
		if (incoming[i] == 0 && !v[i])
			walk(i, curr);
	}

	for(auto &nbr : g[n])
		incoming[nbr] += 1;
	v[n] = false;
}

int main()
{
	bool quit = false;
	FOR(tc, INF)
	{
		g.assign(ALPHA, vi());
		FOR(i,ALPHA)
		{
			v[i] = false;
			incoming[i] = -1;
		}
		s.clear();
		tnodes = 0;

		while(1)
		{
			char c,t;
			int res = scanf("%c%c", &c, &t);

			if (res < 2)
			{
				quit = true;
				break;
			}

			incoming[c-'a'] = 0;
			tnodes += 1;
			if (t == '\n')
				break;
		}

		if (quit)
			break;

		while(1)
		{
			char c1,c2,t;
			int res = scanf("%c %c%c", &c1, &c2, &t);

			g[c1-'a'].push_back(c2-'a');
			if (t == '\n' || res < 3)
				break;
		}

		for(int i=0; i < ALPHA; i++)
		{
			if (incoming[i] == 0 && !v[i])
				walk(i,"");
		}

		if (tc)
			printf("\n");
		for(auto &el : s)
			printf("%s\n", el.c_str());
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