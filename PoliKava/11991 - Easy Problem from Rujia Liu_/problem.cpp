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

void print(const char* msg, ...);

map<int, vi> m;

int main()
{
	int N,M,t,K,V;
	while(scanf("%d %d", &N, &M) == 2)
	{
		m.clear();
		FOR(i, N)
		{
			scanf("%d", &t);
			if (m.find(t) == m.end()) // not found, insert
				m[t] = {i+1};
			else
				m[t].push_back(i+1); // add index
		}

		FOR(i, M)
		{
			scanf("%d %d", &K, &V);
			if (m.find(V) == m.end())
				printf("0\n");
			else
			{
				if (K > m[V].size())
				{
					printf("0\n");
				}
				else
				{
					printf("%d\n", m[V][K-1]);
				}
			}
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