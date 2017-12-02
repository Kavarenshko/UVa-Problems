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
	scanf("%d", &TC);

	getchar();
	FOR(tc, TC)
	{
		string cp;
		getline(cin, cp);

		stack<char> s;
		bool possible = true;
		for(unsigned i=0; i < cp.size(); i++)
		{
			if (s.size() == 0)
				s.push(cp[i]);
			else
			{
				if (cp[i] == ')')
				{
					if (s.top() == '(')
						s.pop();
					else
					{
						possible = false;
						break;
					}
				}
				else if (cp[i] == ']')
				{
					if (s.top() == '[')
						s.pop();
					else
					{
						possible = false;
						break;
					}
				}
				else
				{
					s.push(cp[i]);
				}
			}
		}

		if (s.size() != 0)
			possible = false;

		if (possible)
			printf("Yes\n");
		else
			printf("No\n");
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