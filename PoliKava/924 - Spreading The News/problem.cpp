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

int main()
{
	int E,TC;
	scanf("%d", &E);

	graph g;
	g.assign(E, vi());

	FOR(i,E)
	{
		int N;
		scanf("%d", &N);
		FOR(j,N)
		{
			int t;
			scanf("%d", &t);
			g[i].push_back(t);
		}
	}

	scanf("%d", &TC);
	FOR(tc, TC)
	{
		int source;
		scanf("%d", &source);

		if (g[source].size())
		{
			queue<ii> q;
			set<int> v;

			int day_log[3000];

			for(int i=0; i < 3000; i++)
				day_log[i] = 0;

			v.insert(source);
			q.push({0,source});

			while(!q.empty())
			{
				ii curr = q.front(); q.pop();

				for(auto &nbr : g[curr.second])
				{
					if (v.find(nbr) == v.end())
					{
						day_log[curr.first] += 1;
						q.push({curr.first+1, nbr});
						v.insert(nbr);
					}
				}
			}

			int mvalue,mday;
			mvalue = mday = 0;

			for(int i=0; i < 3000; i++)
			{
				if (day_log[i] > mvalue)
				{
					mvalue = day_log[i];
					mday = i;
				}
			}
			printf("%d %d\n", mvalue, mday+1);
		}
		else
		{
			printf("0\n");
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