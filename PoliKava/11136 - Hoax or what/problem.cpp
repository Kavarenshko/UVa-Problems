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

int main()
{
	int D;
	while(1)
	{
		llu paid = 0;
		multiset<int> a,b;

		scanf("%d", &D);
		if(!D)
			break;

		FOR(d, D) // for every day
		{
			int K;
			scanf("%d", &K);
			FOR(i, K)
			{
				int t;
				scanf("%d", &t);
				a.insert(t);
				b.insert(-t);
			}
			
			int el1, el2;
			el1 = *(a.rbegin());
			el2 = *(b.rbegin());
			paid += el1 + el2;
			a.erase(a.find(el1));
			b.erase(b.find(-el1));
			a.erase(a.find(-el2));
			b.erase(b.find(el2));
		}
		printf("%llu\n", paid);
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