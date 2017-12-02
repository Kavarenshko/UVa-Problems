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

string decapitalize(string s)
{
	for(auto &c : s)
	{
		if (c >= 'A' && c <= 'Z')
			c += 32;
		else if (c >= 'a' && c <= 'z')
			continue;
		else
			*(int*)0 = 0;
	}
	return s;
}

int main()
{
	string current;
	set<string> s;
	while(1)
	{
		if (cin.eof())
			break;
		getline(cin, current);
		if (current == " " || current == "" || current == "\n")
			continue;
		current += " ";

		string word = "";
		for(unsigned i=0; i < current.size(); i++)
		{
			print("\nCurrent word: %s", word.c_str());
			if (current[i] < 'A' || (current[i] > 'Z' && current[i] < 'a') || current[i] > 'z')
			{
				if (word == "")
					continue;
				word = decapitalize(word);
				if (s.find(word) == s.end())
					s.insert(word);
				word = "";
			}
			else
				word += current[i];
		}
	}
	
	for(auto &w : s)
	{
		printf("%s\n", w.c_str());
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