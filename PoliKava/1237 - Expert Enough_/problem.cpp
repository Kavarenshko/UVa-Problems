#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX_DB = 10000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

vector< pair<string, ii> > v;

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int D,Q;
		scanf("%d", &D);

		if (tc)
			printf("\n");

		v.clear();
		FOR(i, D)
		{
			pair<string, ii> p;
			cin >> p.first >> p.second.first >> p.second.second;
			v.push_back(p);
		}
		scanf("%d", &Q);
		FOR(i, Q)
		{
			int QP;
			string company = "";
			bool possible = true;

			scanf("%d", &QP);
			FOR(i, D)
			{
				if (QP >= v[i].second.first && QP <= v[i].second.second)
				{
					if (company == "")
						company = v[i].first;
					else
					{
						possible = false;
						break;
					}
				}
			}

			if (!possible || company == "")
				printf("UNDETERMINED\n");
			else
				printf("%s\n", company.c_str());
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