#include <bits/stdc++.h>

#define FOR(i, n) for(unsigned i=0; i < n; i++)
#define FOR1(i, n) for(unsigned i=1; i <= n; i++)

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

graph g;
vector<bool> lit;
vi steps;

void walk(int p, int prev, int counter, int original, bool m)
{
	print("\nNode %c with prev %c and counter %d.", p+'A', prev+'A', counter);

	if (steps[p] == INF)
		steps[p] = steps[prev] + 1;
	else // loop
	{
		if (!m)
		{
			print(" *%d-%d+1 = %d* ", steps[prev], steps[p], abs(steps[prev]-steps[p])+1);
			if (original > 100*(abs(steps[prev]-steps[p]))+1)
			{
				counter = counter % ((abs(steps[prev]-steps[p]))+1);
				print(" new counter %d", counter);
			}
			m = true;
		}
	}

	if (counter == 0) // lit a candle
	{
		if (!lit[prev])
			printf("%c ", prev+'A');
		lit[prev] = true;
		counter = original-1;
	}
	else
		counter--;

	FOR(i, g[p].size())
	{
		if (g[p][i] == prev)
			continue;

		if (!lit[g[p][i]])
		{
			walk(g[p][i], p, counter, original, m);
			return;
		}
	}
	printf("/%c\n", p+'A');
}

int main()
{
	string current;
	for(int tc=1;;tc++)
	{
		print("\n\nCASE #%d - - - - - - - -\n\n", tc);

		int start_t, start_m;
		getline(cin, current);

		g.clear();

		g.assign(30, vi());
		lit.assign(30, false);
		steps.assign(30, INF);

		if (current == "#" || current == "#\n")
			break;

		unsigned ind;
		int neighbors = -1;
		for(ind=0; ; ind++)
		{
			if (current[ind] == '.')
			{
				ind++;
				break;
			}
			else if (current[ind] == ':')
				continue;
			else if (current[ind] == ';')
			{
				neighbors = -1;
				continue;
			}

			if (neighbors >= 0)
			{
				g[neighbors].push_back(current[ind] - 'A');
			}
			else
			{
				neighbors = current[ind] - 'A';
			}
		}

		bool a[3] = {false, false, false};
		string n = "";
		for(; ind < current.size(); ind++)
		{
			if (current[ind] == ' ')
				continue;
			if (!a[0])
			{
				start_m = current[ind] - 'A';
				a[0] = true;
				continue;
			}
			if (!a[1])
			{
				start_t = current[ind] - 'A';
				a[1] = true;
				continue;
			}
			n += current[ind];
		}
		
		/*for(auto &pos : g)
			sort(pos.begin(), pos.end());*/

		int counter = atoi(n.c_str());

		steps[start_t] = 0;
		walk(start_m, start_t, counter, counter, false);
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