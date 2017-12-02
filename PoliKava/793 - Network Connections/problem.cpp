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
		int possible, impossible;

		scanf("%d", &N);
		getchar();

		if (tc)
			printf("\n");

		possible = impossible = 0;
		UnionFind ufds(N+1);
		while(1)
		{
			char c;
			int a,b;
			string current;
			getline(cin, current);
			if (current == "" || current == " " || current == "\n")
				break;

			sscanf(current.c_str(), "%c %d %d", &c, &a, &b);
			if (c == 'c') // create link, join set
				ufds.unionSet(a,b);
			else if (c == 'q')
			{
				if (ufds.isSameSet(a,b))
					possible += 1;
				else
					impossible += 1;
			}
			else
				*(int*)0 = 0;
		}
		printf("%d,%d\n", possible, impossible);
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