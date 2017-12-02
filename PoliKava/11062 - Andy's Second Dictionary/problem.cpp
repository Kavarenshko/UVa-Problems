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
		if (c == '-')
			continue;
		
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
	bool hyphen = false;
	string current = "";
	set<string> s;
	while(1)
	{
		char c = getchar();
		if (c == EOF)
		{
			if (current != "")
				s.insert(current);
			break;
		}
		print("\nCurrent word: %s", current.c_str());

		if (c == '-')
		{
			hyphen = true;
			continue;
		}
		else if (c == '\n')
		{
			if (hyphen)
				hyphen = false;
			else
			{
				if (current == "")
					continue;
				current = decapitalize(current);
				if (s.find(current) == s.end())
					s.insert(current);
				current = "";
			}
			continue;
		}

		if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		{
			if (current == "")
				continue;
			if (hyphen)
			{
				current += '-';
				hyphen = false;
			}
			current = decapitalize(current);
			if (s.find(current) == s.end())
				s.insert(current);
			current = "";
		}
		else
		{
			if (hyphen)
			{
				current += '-';
				hyphen = false;
			}
			current += c;
		}
	}
	
	for(auto &w : s)
		printf("%s\n", w.c_str());

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