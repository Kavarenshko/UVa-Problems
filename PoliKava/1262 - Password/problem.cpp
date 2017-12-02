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

int K, found;
vector< set<int> > v1, v2;
vector<char> curr;

bool walk(int col)
{
	if (col == 5) // passw is ok
	{
		found += 1;
		if (found == K)
		{
			for(auto &c : curr)
				printf("%c", c);
			//printf("\n");
			return true;
		}
		return false;
	}

	for(auto &c : v1[col]) // lexicographic order
	{
		if (v2[col].find(c) != v2[col].end()) // still valid
		{
			curr.push_back(c);
			if (walk(col+1))
				return true;
			curr.pop_back();
		}
	}
	return false;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		scanf("%d", &K);
		getchar();

		v1.clear();
		v1.assign(5, set<int>());
		v2.clear();
		v2.assign(5, set<int>());
		curr.clear();
		found = 0;

		for(int i=0; i < 6; i++)
		{
			for(int j=0; j < 5; j++)
			{
				char c = getchar();
				v1[j].insert(c);
			}
			getchar();
		}

		for(int i=0; i < 6; i++)
		{
			for(int j=0; j < 5; j++)
			{
				char c = getchar();
				v2[j].insert(c);
			}
			getchar();
		}
		
		if (!walk(0))
			printf("NO");
		printf("\n");

		//break;
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