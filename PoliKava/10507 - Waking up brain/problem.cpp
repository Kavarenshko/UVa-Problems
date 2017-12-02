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
	int M;
	unsigned int N;
	set<char> s;
	map< char, vector<char> > m;
	while(1)
	{
		if (scanf("%u %d", &N, &M) != 2)
			break;

		s.clear();
		m.clear();

		getchar();
		for(int i=0; i < 3; i++)
			s.insert(getchar());
		for(auto &c : s)
			print("%c\n", c);
		getchar();

		FOR(i, M)
		{
			char c1,c2;
			c1 = getchar(); c2 = getchar(); getchar();

			if (m.find(c1) == m.end())
				m[c1] = {c2};
			else
				m[c1].push_back(c2);
			if (m.find(c2) == m.end())
				m[c2] = {c1};
			else
				m[c2].push_back(c1);
		}

		if (s.size() == N)
		{
			printf("WAKE UP IN, 0, YEARS\n");
			continue;
		}

		int cyears;
		bool awoken, solved = false;
		for(cyears = 1; cyears < INF; cyears++)
		{
			awoken = false;
			set<char> provisional;
			for(auto &c : m)
			{
				if (s.find(c.first) == s.end()) // still sleeping
				{
					int living_nbrs = 0;
					for(auto &nbr : c.second)
					{
						if (s.find(nbr) != s.end())
							living_nbrs += 1;
					}
					if (living_nbrs >= 3)
					{
						awoken = true;
						print("\nNode %c wakes up at year %d", c.first, cyears);
						provisional.insert(c.first);
					}
				}
			}

			for(auto &ncell : provisional)
				s.insert(ncell);

			if (s.size() == N)
			{
				solved = true;
				break;
			}

			if (!awoken)
				break;
		}

		if (!solved)
			printf("THIS BRAIN NEVER WAKES UP\n");
		else
			printf("WAKE UP IN, %d, YEARS\n", cyears);
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