#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int LIMIT = 20001;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

bool found;
int N,M,S,T;
int dist[LIMIT];

vector<vector<ii>> g;

int main()
{
	int TC;
	cin >> TC;

	for(int tc=1; tc <= TC; tc++)
	{
		printf("Case #%d: ", tc);

		cin >> N >> M >> S >> T;

		found = false;

		g.clear();
		g.assign(N, vector<ii>());
		for(int i=0; i < M; i++)
		{
			int a,b,w;
			cin >> a >> b >> w;

			g[a].push_back({b,w});
			g[b].push_back({a,w});
		}

		for(int i=0; i < N; i++)
			dist[i] = INF;

		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.push({0, S});

		while(pq.size())
		{
			ii curr = pq.top(); pq.pop();

			if (curr.second == T)
			{
				printf("%d\n", curr.first);
				found = true;
				break;
			}

			if (curr.first > dist[curr.second]) // lazy deletion
				continue;

			for(unsigned i=0; i < g[curr.second].size(); i++)
			{
				int nb_ind = g[curr.second][i].first;
				int nb_wt = g[curr.second][i].second;
				if (curr.first + nb_wt < dist[nb_ind])
				{
					dist[nb_ind] = curr.first + nb_wt;
					pq.push({curr.first + nb_wt, nb_ind});
				}
			}
		}

		if (found == false)
			printf("unreachable\n");
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