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
	int N;
	while(1)
	{
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool p_stack = true;
		bool p_queue = true;
		bool p_pq = true;

		if (scanf("%d", &N) != 1)
			break;

		FOR(i, N)
		{
			int command, num;
			scanf("%d %d", &command, &num);

			if (command == 1)
			{
				if (p_stack) // still valid
					s.push(num);
				if (p_queue)
					q.push(num);
				if (p_pq)
					pq.push(num);
			}
			else if (command == 2)
			{
				if (s.size() && s.top() == num && p_stack)
					s.pop();
				else
					p_stack = false;
				if (q.size() && q.front() == num && p_queue)
					q.pop();
				else
					p_queue = false;
				if (pq.size() && pq.top() == num && p_pq)
					pq.pop();
				else
					p_pq = false;
			}
		}

		if (p_stack && !p_queue && !p_pq)
			printf("stack\n");
		else if (!p_stack && p_queue && !p_pq)
			printf("queue\n");
		else if (!p_stack && !p_queue && p_pq)
			printf("priority queue\n");
		else if (!p_stack && !p_queue && !p_pq)
			printf("impossible\n");
		else
			printf("not sure\n");
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