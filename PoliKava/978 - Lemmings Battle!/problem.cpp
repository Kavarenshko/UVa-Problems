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
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int NG, NB, t;
		unsigned long B;
		vi insert_green, insert_blue;
		priority_queue<int> green, blue;

		scanf("%lu %d %d", &B, &NG, &NB);

		if (tc) printf("\n");

		FOR(i, NG)
		{
			scanf("%d", &t);
			green.push(t);
		}

		FOR(i, NB)
		{
			scanf("%d", &t);
			blue.push(t);
		}

		while(1)
		{
			if (green.size() == 0 && blue.size() == 0)
			{
				printf("green and blue died\n");
				break;
			}

			if (green.size() == 0)
			{
				printf("blue wins\n");
				while(!blue.empty())
				{
					int el = blue.top(); blue.pop();
					printf("%d\n", el);
				}
				break;
			}
			if (blue.size() == 0)
			{
				printf("green wins\n");
				while(!green.empty())
				{
					int el = green.top(); green.pop();
					printf("%d\n", el);
				}
				break;
			}

			insert_green.clear();
			insert_blue.clear();

			unsigned long limit = min(B, min(green.size(), blue.size()));
			for(unsigned long i=0; i < limit; i++)
			{
				int g = green.top(), b = blue.top();
				green.pop();
				blue.pop();

				if (g > b)
					insert_green.push_back(g-b);
				else if (g < b)
					insert_blue.push_back(b-g);
			}

			for(auto &el : insert_green)
				green.push(el);
			for(auto &el : insert_blue)
				blue.push(el);
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