#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N;
int dist[20][20];
double minpath;
vi minSol;
vi currSol;
vector< pair<ii, bool> > v;

double getDistance(int n1, int n2)
{
	return sqrt((v[n1].first.first - v[n2].first.first) * (v[n1].first.first - v[n2].first.first) + (v[n1].first.second - v[n2].first.second) * (v[n1].first.second - v[n2].first.second));
}

void walk(int node, double d)
{
	/*print("\n\nCurrent node = %d, dist = %.2lf.\n", node, dist);

	for(auto &el : currSol)
		print("\n  - %d", el);
	print("\nMinSol:\n");
	for(auto &el : minSol)
		print("\n  - %d", el);*/
	
	if (d > minpath) // discard solution
		return;

	currSol.push_back(node);
	v[node].second = true; // mark as visited

	bool full = true;
	for(int i=0; i < N; i++)
	{
		if (v[i].second == false)
		{
			walk(i, d + dist[node][i]);
			full = false;
		}
	}

	if (full)
	{
		minpath = min(minpath, d); // should be useless, could be minpath = dist
		minSol = currSol;
	}

	currSol.pop_back();
	v[node].second = false;
}

int main()
{

	FOR1(tc, INF)
	{
		scanf("%d", &N);
		if (!N)
			break;

		printf("**********************************************************\nNetwork #%d\n", tc);
		
		minpath = INF;
		v.clear();
		minSol.clear();
		currSol.clear();

		FOR(i, N)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			v.push_back({{a,b},false});
		}

		FOR(i, N)
			FOR(j, N)
				dist[i][j] = getDistance(i, j);

		for(int i=0; i < N; i++)
			walk(i, 0.0);

		for(int i=0; i < N-1; i++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", v[minSol[i]].first.first, v[minSol[i]].first.second, v[minSol[i+1]].first.first, v[minSol[i+1]].first.second, dist[minSol[i]][minSol[i+1]] + 16.00);
		}
		printf("Number of feet of cable required is %.2lf.\n", minpath + (16.00*(N-1)));
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