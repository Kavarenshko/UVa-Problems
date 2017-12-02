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
	FOR(tc, INF)
	{
		int N;
		scanf("%d", &N);

		if(!N)
			break;

		while(1) // read permutations (1-N)
		{
			int t;
			stack<int> s;
			vector<int> v;
			queue<int> q;

			FOR1(i, N)
				q.push(i);

			FOR(i, N)
			{
				scanf("%d", &t);
				if (!t)
					break;
				v.push_back(t);
			}
			if(!t)
				break;

			bool possible = true;
			for(auto &el : v)
			{
				if (q.size() == 0 || el < q.front()) // must be already in stack
				{
					if (s.size() > 0 && s.top() == el)
						s.pop();
					else
					{
						possible = false;
						break;
					}
				}
				else
				{
					while(el > q.front())
					{
						s.push(q.front());
						q.pop();
					}
					q.pop();
				}
			}
			if (possible)
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
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