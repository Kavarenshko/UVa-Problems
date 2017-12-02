#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 502;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int calcDistance(int n1, int n2)
{
	string s1,s2;
	s1 = to_string(n1);
	s2 = to_string(n2);

	while(s1.size() < 4) s1 = "0" + s1;
	while(s2.size() < 4) s2 = "0" + s2;

	int p = 0;
	for(int i=0; i < 4; i++)
	{
		int d1,d2,res;
		d1 = s1[i] - '0';
		d2 = s2[i] - '0';
		if (d1 > d2)
			res = d2 + (9-d1)+1;
		else
			res = d1 + (9-d2)+1;
		p += min(abs(d1-d2), res);
	}
	return p;
}

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
		int N;
		vi keys;

		scanf("%d", &N);
		FOR(i,N)
		{
			int t;
			scanf("%d", &t);
			keys.push_back(t);
		}

		UnionFind ufds(N+1);
		vector< pair<int, ii> > edges;
		for(int i=0; i < (int)keys.size(); i++)
		{
			for(int j=i+1; j < (int)keys.size(); j++)
			{
				edges.push_back({calcDistance(keys[i], keys[j]), {i,j}});
			}
		}

		sort(edges.begin(), edges.end());

		int count = 0;
		int cost = 0;
		for(int i=0; i < (int)edges.size(); i++)
		{
			if (count == N-1)
				break;
			pair<int, ii> p = edges[i];
			if (!ufds.isSameSet(p.second.first, p.second.second))
			{
				cost += p.first;
				ufds.unionSet(p.second.first, p.second.second);
				count += 1;
			}
		}

		int mvalue = INF;
		for(int i=0; i < (int)keys.size(); i++)
		{
			int mem = calcDistance(0, keys[i]);
			if (mem < mvalue)
				mvalue = mem;
		}

		cost += mvalue;
		printf("%d\n", cost);

		/*while(u.size())
		{
			mvalue = INF;

			for(auto &vis : v)
			{
				for(int i=0; i < (int)u.size(); i++)
				{
					if (dist[] < mvalue)
					{
						mvalue = mem;
						mindex = i;
					}
				}
			}
			p += mvalue;
			v.push_back(u[mindex]);
			u.erase(u.begin()+mindex);
		}
		printf("%d\n", p);*/
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