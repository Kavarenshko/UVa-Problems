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

class ComparatorClass
{
public:
	bool operator() (int a, int b)
	{
		if (a < b)
			return false;
		return true;
	}
};

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int M,N,t,ind;
		queue<int> q;
		vector<int> queries;
		multiset<int> s;
		multiset<int>::iterator it;

		scanf("%d %d", &M, &N);
		if (tc)
			printf("\n");

		FOR(i, M)
		{
			scanf("%d", &t);
			q.push(t);
		}
		FOR(i, N)
		{
			scanf("%d", &t);
			queries.push_back(t);
		}

		s.insert(q.front()); q.pop(); // insert first element
		it = s.begin();
		for(int i=0; i < queries.size(); i++)
		{
			while(queries[i] > s.size())
			{
				int next = q.front(); q.pop();
				s.insert(next);
				if (next < *it)
					it--;
			}
			if (i)
				it++;
			printf("%d\n", *it);
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