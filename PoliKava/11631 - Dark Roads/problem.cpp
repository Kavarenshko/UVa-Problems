#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

class UnionFind
{
private:
	vi p, rank;
public:
	UnionFind(int N)
	{
		rank.assign(N, 0);
		FOR(i, N)
			p.push_back(i);
	}
	int findSet(int i)
	{
		if (p[i] == i)
			return i;
		p[i] = findSet(p[i]);
		return p[i];
	}
	bool isSameSet(int i, int j) { return (findSet(i) == findSet(j)); }
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x,y;
			x = findSet(i);
			y = findSet(j);

			if (rank[x] > rank[y])
				p[y] = x;
			else
			{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y] += 1;
			}
		}
	}
};

int main()
{
	FOR(tc, INF)
	{
		int N,M;
		ll tot_cost = 0;

		scanf("%d %d", &M, &N);
		if (!N && !M)
			break;

		UnionFind u(M);
		vector< pair<int, ii> > edges;
		FOR(i,N)
		{
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			edges.push_back({w, {a,b}});
			tot_cost += w;
		}

		sort(edges.begin(), edges.end());
		ll min_cost = 0;
		for(int i=0; i < (int)edges.size(); i++)
		{
			if (!u.isSameSet(edges[i].second.first, edges[i].second.second))
			{
				min_cost += edges[i].first;
				u.unionSet(edges[i].second.first, edges[i].second.second);
			}
		}
		printf("%lld\n", tot_cost-min_cost);
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