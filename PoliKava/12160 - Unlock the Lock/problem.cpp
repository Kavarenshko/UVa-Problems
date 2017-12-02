#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 10000;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int main()
{
	vi b;
	bool v[MAX];

	FOR1(tc, INF)
	{
		int C,G,R;
		scanf("%d %d %d", &C, &G, &R);

		if (!C && !G && !R)
			break;

		FOR(i,MAX)
			v[i] = false;
		b.clear();

		FOR(i,R)
		{
			int t;
			scanf("%d", &t);
			b.push_back(t);
		}

		priority_queue<ii> pq;
		pq.push({0,C});
		v[C] = true;

		bool solution = false;
		int mvalue = MAX;
		while(!pq.empty())
		{
			ii curr = pq.top(); pq.pop();

			if (curr.second == G)
			{
				solution = true;
				mvalue = -curr.first;
				break;
			}

			for(auto &el : b)
			{
				int next_state = (curr.second + el) % MAX;
				if (!v[next_state])
				{
					pq.push({curr.first-1, next_state});
					v[next_state] = true;
				}
			}
		}

		if (solution)
			printf("Case %d: %d\n", tc, mvalue);
		else
			printf("Case %d: Permanently Locked\n", tc);
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