#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

unsigned long N;

vector<string> sol;

string leading(ll n1, unsigned digits)
{
	string s = to_string(n1);
	while(s.size() < digits)
		s = "0" + s;
	return s;
}

void gen()
{
	for(ll i=0; i <= 9999; i++)
	{
		for(ll j=0; j <= 9999; j++)
		{
			if (i <= 9 && j <= 9)
			{
				if ((i+j)*(i+j) == 10*i+j)
					sol.push_back(leading(10*i+j, 2));
			}
			if (i <= 99 && j <= 99)
			{
				if ((i+j)*(i+j) == 100*i+j)
					sol.push_back(leading(100*i+j, 4));
			}
			if (i <= 999 && j <= 999)
			{
				if ((i+j)*(i+j) == 1000*i+j)
					sol.push_back(leading(1000*i+j, 6));
			}
			if ((i+j)*(i+j) == 10000*i+j)
				sol.push_back(leading(10000*i+j, 8));
		}
	}
}

int main()
{
	gen();
	while(scanf("%lu", &N) == 1)
	{
		for(auto &s : sol)
		{
			if (s.size() == N)
				printf("%s\n", s.c_str());
		}
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