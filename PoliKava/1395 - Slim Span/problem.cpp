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
typedef tuple<int, int, int> status;

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

int N,M,edge_max,edge_min;
vector<status> v;
set<int> connected;

bool walk(graph& gph, int ind)
{
	connected.insert(ind);
	for(unsigned i=0; i < gph[ind].size(); i++)
	{
		if (connected.count(gph[ind][i]) == 0)
			walk(gph, gph[ind][i]);
	}

	return (connected.size() == N);
}

int main()
{
	while(1)
	{
		scanf("%d %d", &N, &M);

		if (N == 0 && M == 0)
			break;

		graph g;
		g.assign(N+1, vi());

		v.clear();
		connected.clear();
		edge_max = -1;
		edge_min = INF;

		FOR(i, M)
		{
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			v.push_back(make_tuple(w,a,b));
			g[a].push_back(b);
			g[b].push_back(a);

			edge_max = max(edge_max, w);
			edge_min = min(edge_min, w);
		}

		sort(v.begin(), v.end());

		if (walk(g, 1) == false)
		{
			printf("-1\n");
			continue;
		}

		int edge_diff = edge_max - edge_min;
		for(unsigned i=0; i < v.size();  i++)
		{
			int rand_start;
			int curr_min = INF;
			int curr_max = -1;

			graph temp;
			temp.assign(N+1, vi());

			UnionFind ufds(N+1);
			for(unsigned j=i; j < v.size(); j++)
			{
				int w,a,b;
				tie(w,a,b) = v[j];
				if (!ufds.isSameSet(a, b))
				{
					curr_min = min(curr_min, w);
					curr_max = max(curr_max, w);
					temp[a].push_back(b);
					temp[b].push_back(a);

					ufds.unionSet(a,b);
					rand_start = a;
				}
			}

			connected.clear();
			if (walk(temp, rand_start))
				edge_diff = max(0, min(edge_diff, curr_max - curr_min));
		}

		printf("%d\n", edge_diff);
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