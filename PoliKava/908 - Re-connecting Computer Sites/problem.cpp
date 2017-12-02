#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 1000000;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int V,K,M;

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
	FOR(tc,INF)
	{
		vector< pair<int,ii> > edges;

		if (scanf("%d", &V) != 1)
			break;

		ll prev_value = 0;
		int ufds_value = -1;
		FOR(i,V-1)
		{
			int w;
			scanf("%*d %*d %d", &w);
			prev_value += w;
		}

		scanf("%d", &K);
		FOR(i,K)
		{
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);

			if (a < b)
				edges.push_back({w, {a,b}});
			else
				edges.push_back({w, {b,a}});
		}

		scanf("%d", &M);
		FOR(i,M)
		{
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			if (a < b)
				edges.push_back({w, {a,b}});
			else
				edges.push_back({w, {b,a}});
			ufds_value = max(ufds_value, max(a,b));
		}
		sort(edges.begin(), edges.end());
		UnionFind u(ufds_value+1);
		ll tot_cost = 0;
		for(int i=0; i < (int)edges.size(); i++)
		{
			if (!u.isSameSet(edges[i].second.first, edges[i].second.second))
			{
				tot_cost += edges[i].first;
				u.unionSet(edges[i].second.first, edges[i].second.second);
			}
		}
		if (tc)
			printf("\n");
		printf("%lld\n%lld\n", prev_value, tot_cost);
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