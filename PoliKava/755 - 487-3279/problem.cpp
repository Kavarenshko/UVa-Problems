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

map<string, int> m;
set<string> ss;

string getEquivalent(string s) // no hyphens
{
	string n = "";

	for(auto c : s)
	{
		if (c >= 'A' && c <= 'Z')
		{
			if (c >= 'A' && c <= 'C')
				n += "2";
			else if (c >= 'D' && c <= 'F')
				n += "3";
			else if (c >= 'G' && c <= 'I')
				n += "4";
			else if (c >= 'J' && c <= 'L')
				n += "5";
			else if (c >= 'M' && c <= 'O')
				n += "6";
			else if (c >= 'P' && c <= 'S')
				n += "7";
			else if (c >= 'T' && c <= 'V')
				n += "8";
			else if (c >= 'W' && c <= 'Y')
				n += "9";
			else
				*(int*)0 = 0;
		}
		else if (c >= '0' && c <= '9')
			n += c;
	}
	return n;
}

int main()
{
	int N;
	bool started = false;

	scanf("%d", &N);
	FOR1(tc, N)
	{
		int K;
		scanf("%d", &K);

		while(1)
			if (getchar() == '\n')
				break;

		if (!started)
			started = true;
		else
			printf("\n");

		m.clear();
		ss.clear();

		print("\n\nNEW CASE - - - - - - -\n\n");

		FOR(i, K)
		{
			string s;
			getline(cin, s);

			s = getEquivalent(s);
			if (m.find(s) == m.end())
			{
				m[s] = 1;
				ss.insert(s);
			}
			else
				m[s] += 1;

			print("\\%s/\n", s.c_str());
		}

		bool duplicates = false;
		for(auto &el : ss)
		{
			print("*%s*\n", el.c_str());
			if (m[el] > 1)
			{
				printf("%s-%s %d\n", el.substr(0,3).c_str(), el.substr(3).c_str(), m[el]);
				duplicates = true;
			}
		}

		if (!duplicates)
			printf("No duplicates.\n");
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