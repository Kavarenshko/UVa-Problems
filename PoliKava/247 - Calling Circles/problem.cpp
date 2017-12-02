#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)
#define UNVISITED -1

using namespace std;

constexpr int MAX_PEOPLE = 26;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N,M;
int dfs_counter, scc_counter;

graph g;
map<string, int> names;
map<int, string> rev;

vi dfs_num, dfs_low, visited;
stack<int> s;

vector<vector<int>> scc;

void SCC(int u)
{
	dfs_low[u] = dfs_num[u] = dfs_counter++;
	s.push(u);
	visited[u] = 1;

	for(unsigned i=0; i < g[u].size(); i++)
	{
		int nb = g[u][i];
		if (dfs_num[nb] == UNVISITED) // neighbor has never been visited before
			SCC(nb);

		if (visited[nb]) // if this node is not part of another SCC
			dfs_low[u] = min(dfs_low[u], dfs_low[nb]);
	}

	if (dfs_num[u] == dfs_low[u]) // if this node is the root of a SCC subtree
	{
		scc.push_back(vi());

		int current_node;
		while(1)
		{
			current_node = s.top();
			s.pop();

			visited[current_node] = 0;
			scc[scc_counter].push_back(current_node);

			if (current_node == u)
				break;
		}
		scc_counter += 1;
	}
}

int main()
{
	for(int tc=1; ; tc++)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		if (tc > 1)
			printf("\n");

		dfs_counter = 0;
		scc_counter = 0;

		names.clear();
		rev.clear();

		g.clear();
		g.assign(N+1, vi());

		dfs_num.clear();
		dfs_num.assign(N+1, UNVISITED);

		dfs_low.clear();
		dfs_low.assign(N+1, UNVISITED);

		visited.clear();
		visited.assign(N+1, 0);

		//s.clear(); // should already be clear
		scc.clear();

		for(int i=0; i < M; i++)
		{
			int ind_a, ind_b;
			string a,b;

			cin >> a >> b;

			if (names.count(a))
				ind_a = names[a];
			else
			{
				ind_a = names.size();
				names[a] = ind_a;
				rev[ind_a] = a;
			}

			if (names.count(b))
				ind_b = names[b];
			else
			{
				ind_b = names.size();
				names[b] = ind_b;
				rev[ind_b] = b;
			}

			g[ind_a].push_back(ind_b);
		}

		for(int i=0; i < N; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				SCC(i);
			}
		}

		printf("Calling circles for data set %d:\n", tc);
		for(auto &scc_v : scc) // scc_v is the vector containing nodes of this scc
		{
			unsigned scc_len = scc_v.size();
			for(unsigned i=0; i < (scc_len)-1; i++) // do not print last comma
				printf("%s, ", rev[scc_v[i]].c_str());
			printf("%s\n", rev[scc_v.back()].c_str());
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