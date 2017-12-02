#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX_GROUPS = 500;
constexpr int MAX_STUDENTS = 30000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

bool v_group[MAX_GROUPS];
bool v_student[MAX_STUDENTS];

graph g,v;

int walk(int n)
{
	int tot = 1;
	v_student[n] = true;

	for(auto &gr : v[n])
	{
		if (v_group[gr]) // group already visited
			continue;
		v_group[gr] = true;
		for(auto &member : g[gr])
		{
			if (v_student[member]) // student already visited
				continue;
			tot += walk(member);
		}
	}
	return tot;
}

int main()
{
	int N,M;
	while(1)
	{
		scanf("%d %d", &N, &M);
		if (!N && !M)
			break;

		FOR(i, MAX_GROUPS)
			v_group[i] = false;
		FOR(i, MAX_STUDENTS)
			v_student[i] = false;

		g.assign(M, vi());
		v.assign(N, vi());
		FOR(i, M)
		{
			int K,t;
			scanf("%d", &K);

			FOR(j, K)
			{
				scanf("%d", &t);
				g[i].push_back(t);
				v[t].push_back(i);
			}
		}

		printf("%d\n", walk(0));
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