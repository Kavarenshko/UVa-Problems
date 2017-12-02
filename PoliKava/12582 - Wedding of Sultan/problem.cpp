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
	int TC;
	stack<char> s;
	map<char, int> m;
	string f;
	scanf("%d", &TC);

	getchar();
	FOR1(tc, TC)
	{
		printf("Case %d\n", tc);

		//s.clear();
		m.clear();
		getline(cin, f);

		for(auto &c : f)
		{
			if (s.size() == 0)
			{
				s.push(c);
				m[c] = 0;
			}
			else
			{
				if (c == s.top())
				{
					if (m[s.top()] == 0)
						m[s.top()] = 1;
					s.pop();
				}
				else
				{
					m[s.top()] += 1;
					s.push(c);
					m[c] = 1;
				}
			}
		}

		for(auto &kv : m)
			printf("%c = %d\n", kv.first, kv.second);
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