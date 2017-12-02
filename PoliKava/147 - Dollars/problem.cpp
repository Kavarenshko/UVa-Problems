#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr double EPS = 1e-9;
constexpr int MAX_COINS = 11;
constexpr int MAX_STATES = 30010;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int v;
ll dp[MAX_COINS][MAX_STATES];

int process(double n)
{
	int cdigits = 0;
	bool post = false;
	string s = to_string(n);
	string r = "";
	for(auto &c : s)
	{
		if (post)
		{
			cdigits += 1;
			if (cdigits == 3)
				break;
		}

		if (c == '.')
		{
			post = true;
			continue;
		}
		else
			r += c;
	}
	return stoi(r);
}

ll walk(int ind, int rem)
{
	int val[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

	if (dp[ind][rem] != -1)
		return dp[ind][rem];
	if (ind == -1 || rem < 5)
		return 0;

	if (ind == 0)
		return dp[ind][rem] = 1;
	if (rem < val[ind])
		return dp[ind][rem] = walk(ind-1, rem);

	ll curr_sol = 0;
	int cp = rem; // we will need rem later
	while(cp >= val[ind])
	{
		curr_sol += walk(ind-1, cp);
		cp -= val[ind];
	}
	if (cp)
		curr_sol += walk(ind-1, cp);
	else
		curr_sol += 1;

	return dp[ind][rem] = curr_sol;
}

int main()
{
	double n;

	FOR(i, MAX_COINS)
			FOR(j, MAX_STATES)
				dp[i][j] = -1;

	while(1)
	{
		scanf("%lf", &n);
		if (n <= EPS) // 0.0
			break;

		v = process(n);
		walk(10, v);
		printf("%6.2lf%17lld\n", n, dp[10][v]);
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