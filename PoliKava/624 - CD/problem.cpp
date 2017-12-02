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

typedef pair<int, set<int> > is;

void print(const char* msg, ...);

unsigned K;
long N,t,solRem;
vector<long> v, sol, curr;

bool walk(ll r, unsigned ind)
{
	print("\nRemaining %ld at index %u, ", r, ind);
	if (r < solRem)
	{
		print("best solution so far\n  > ");
		for(auto &el : curr)
			print("%ld ", el);
		solRem = r;
		sol = curr;
	}
	else if (r == 0)
	{
		print("optimal solution!");
		solRem = 0;
		sol = curr;
		return true;
	}

	for(unsigned i=ind+1; i < K; i++)
	{
		if (r - v[i] >= 0)
		{
			curr.push_back(v[i]);
			if (walk(r-v[i], i))
				return true;
			curr.pop_back();
		}
	}
	return false;
}

int main()
{
	FOR(tc, INF)
	{
		if (scanf("%ld %u", &N, &K) != 2)
			break;

		solRem = INF; // if 0 the solution is optimal
		v.clear();
		sol.clear();
		curr.clear();
		for(unsigned i=0; i < K; i++)
		{
			scanf("%ld", &t);
			v.push_back(t);
		}

		for(unsigned i=0; i < K; i++)
		{
			curr.push_back(v[i]);
			if (walk(N-v[i], i))
				break;
			curr.pop_back();
			if (curr.size() != 0)
			{
				//print("\nSize is not 0!");
				*(int*)0 = 0;
			}
		}

		for(auto &el : sol)
			printf("%ld ", el);
		printf("sum:%ld\n", N-solRem);
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