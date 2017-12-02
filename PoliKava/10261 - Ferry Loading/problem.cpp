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

vi v;
vector<char> sol, curr;
set< pair<int, ii> > s;

void walk(unsigned ind, int l, int r)
{

	if (l <= r)
	{
		if (s.find({ind, {l,r}}) == s.end())
			s.insert({ind, {l,r}});
		else
			return;
	}
	else
	{
		if (s.find({ind, {r,l}}) == s.end())
			s.insert({ind, {r,l}});
		else
			return;
	}

	if (ind == v.size() || (v[ind] > l && v[ind] > r)) // all cars have been loaded
	{
		if (curr.size() > sol.size())
			sol = curr;
		return;
	}

	if (l >= v[ind]) // there's still some space here
	{
		curr.push_back('p');
		walk(ind+1, l - v[ind], r);
		curr.pop_back();
	}
	if (r >= v[ind])
	{
		curr.push_back('s');
		walk(ind+1, l, r - v[ind]);
		curr.pop_back();
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int length,t;

		scanf("%d", &length);

		if (tc)
			printf("\n");

		s.clear();
		v.clear();
		sol.clear();
		curr.clear();

		while(1)
		{
			scanf("%d", &t);
			if (!t)
				break;
			v.push_back(t);
		}

		walk(0, length*100, length*100);

		printf("%lu\n", sol.size());
		for(auto &el : sol)
		{
			if (el == 'p')
				printf("port\n");
			else
				printf("starboard\n");
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