#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N,M;
vector<string> pwds, rules, expand;

void process(string r, unsigned ind, string pwd, string curr)
{
	if (ind == r.size())
	{
		printf("%s\n", curr.c_str());
		return;
	}

	if (r[ind] == '#')
	{
		curr += pwd;
		process(r, ind+1, pwd, curr);
	}
	else if (r[ind] == '0')
	{
		for(unsigned i=0; i < 10; i++)
			process(r, ind+1, pwd, curr + static_cast<char>('0'+i));
	}
	else
		*(int*)0 = 0;
}

int main()
{
	string current;
	while(1)
	{
		if (scanf("%d", &N) != 1)
			break;
		printf("--\n");

		getchar();
		pwds.clear();
		FOR(i, N)
		{
			getline(cin, current);
			pwds.push_back(current);
		}

		scanf("%d", &M);

		getchar();
		rules.clear();
		FOR(i, M)
		{
			getline(cin, current);
			rules.push_back(current);
		}

		for(auto &r : rules)
			for(auto &w : pwds)
				process(r, 0, w, "");
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