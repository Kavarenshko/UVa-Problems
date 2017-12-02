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
	int N,t;
	ll cost;
	while(1)
	{
		scanf("%d", &N);
		if (!N)
			break;

		priority_queue<ll> pq;
		cost = 0;
		FOR(i, N)
		{
			scanf("%d", &t);
			pq.push(-t);
		}

		while(1)
		{
			if (pq.size() == 1) // result
				break;
			ll n1, n2;
			n1 = pq.top(); pq.pop();
			n2 = pq.top(); pq.pop();

			cost += -n1-n2;
			pq.push(n1+n2);
		}
		printf("%lld\n", cost);
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