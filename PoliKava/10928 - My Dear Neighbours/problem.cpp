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
		print("\n\nTEST CASE - - - - - - -\n\n");
		int P, r;
		vi solutions;
		scanf("%d", &P);

		int min_count = INF;
		int count = 0;
		for(int i=1; i <= P;)
		{
			scanf("%d", &r);
			count++;

			char c = getchar();
			print("\n*%c*", c);
			if (c == '\n' || c == EOF)
			{
				if (count < min_count)
				{
					min_count = count;
					solutions.clear();
					solutions.push_back(i);
				}
				else if (count == min_count)
					solutions.push_back(i);
				i++;
				count = 0;
			}
		}

		if (solutions.size() == 1)
			printf("%d\n", solutions.front());
		else
		{
			for(int i=0; i < solutions.size()-1; i++)
				printf("%d ", solutions[i]);
			printf("%d\n", solutions.back());
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