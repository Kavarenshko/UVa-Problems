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

map<string,int> m;

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
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int N,M;
		vector< pair<int,ii> > edges;
		scanf("%d %d", &M, &N);
		getchar();

		UnionFind u(M+1);
		m.clear();
		FOR(i, N)
		{
			int w;
			string c1,c2;
			cin >> c1 >> c2 >> w;

			if (m.find(c1) == m.end())
				m[c1] = (int)m.size();
			if (m.find(c2) == m.end())
				m[c2] = (int)m.size();
			edges.push_back({w, {m[c1], m[c2]}});
		}

		sort(edges.begin(), edges.end());
		int tot_cost = 0;
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
		printf("%d\n", tot_cost);
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