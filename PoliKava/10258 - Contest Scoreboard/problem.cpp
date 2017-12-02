#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int CONTESTANTS = 101;
constexpr int PROBLEMS = 10;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

ii m[CONTESTANTS][PROBLEMS];
bool printed[CONTESTANTS];

bool compareElements(pair<int, ii> a, pair<int, ii> b)
{
	if (a.second.first < b.second.first) // #solved
		return false;
	else if (a.second.first > b.second.first)
		return true;

	// #solved == #solved

	if (a.second.second < b.second.second)
		return true;
	else if (a.second.second > b.second.second)
		return false;

	// penalty time == penalty time

	if (a.first < b.first)
		return true;
	return false;
}

int main()
{
	int TC;

	scanf("%d", &TC);

	getchar();
	getchar();

	FOR(tc, TC)
	{
		string current;
		vector< pair<int, ii> > scoreboard;

		if (tc)
			printf("\n");

		print("\nTEST CASE - - - - - - -");

		FOR(i, CONTESTANTS)
			FOR(j, PROBLEMS)
				m[i][j] = {0,0};
		FOR(i, CONTESTANTS)
			printed[i] = false;

		while(1) // get data
		{
			if (cin.eof())
				break;

			getline(cin, current);
			if (current == "" || current == " " || current == "\n")
				break;

			int id, problem, t;
			char c;
			sscanf(current.c_str(), "%d %d %d %c", &id, &problem, &t, &c);
			
			printed[id] = true; // this contestant will appear in the final scoreboard
			if (c == 'R' || c == 'U' || c == 'E')
				continue;

			if (m[id][problem].first) // already solved
					continue;

			if (c == 'C') // correct
				m[id][problem].first = t;
			else if (c == 'I')
				m[id][problem].second += 1;
			else
				*(int*)0 = 0;
		}

		// print results

		FOR(i, CONTESTANTS)
		{
			if (!printed[i])
				continue;

			pair<int, ii> p = {i, {0, 0}}; // id, #solved, penalty time

			FOR(j, PROBLEMS)
			{
				if (!m[i][j].first)
					continue;
				p.second.first += 1;
				p.second.second += m[i][j].first;
				p.second.second += 20 * m[i][j].second;
			}

			scoreboard.push_back(p);
		}
		sort(scoreboard.begin(), scoreboard.end(), compareElements);
		for(auto &cs : scoreboard)
			printf("%d %d %d\n", cs.first, cs.second.first, cs.second.second);
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