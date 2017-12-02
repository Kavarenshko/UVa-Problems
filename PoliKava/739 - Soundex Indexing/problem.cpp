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
	vector< pair<set<char>, int> > v;

	set<char> s0 = {'A','E','I','O','U','Y','W','H'};
	set<char> s1 = {'B','P','V','F'};
	set<char> s2 = {'C','S','K','G','J','Q','X','Z'};
	set<char> s3 = {'D','T'};
	set<char> s4 = {'L'};
	set<char> s5 = {'M','N'};
	set<char> s6 = {'R'};
	v.push_back({s0,0});
	v.push_back({s1,1});
	v.push_back({s2,2});
	v.push_back({s3,3});
	v.push_back({s4,4});
	v.push_back({s5,5});
	v.push_back({s6,6});
	printf("         NAME                     SOUNDEX CODE");
	while(!cin.eof())
	{
		string curr_str, soundex = "";
		getline(cin, curr_str);
		if (curr_str == "" || curr_str == "\n")
			break;
		printf("\n         %s", curr_str.c_str());
		for(unsigned i=0; i < (25 - curr_str.size()); i++)
			printf(" ");
		//bool clear = true;

		soundex += curr_str[0];
		char last = curr_str[0];
		for(unsigned i=1; i < curr_str.size(); i++)
		{
			if (soundex.size() == 4)
				break;

			int last_idx, curr_idx;
			for(auto &el : v)
			{
				if (el.first.find(curr_str[i]) != el.first.end())
					curr_idx = el.second;
				if (el.first.find(last) != el.first.end())
					last_idx = el.second;
			}

			if (curr_idx != 0)
			{
				if (last_idx == curr_idx)
					continue;
				else
					soundex += ('0' + curr_idx);
			}
			last = curr_str[i];
		}
		while(soundex.size() < 4)
			soundex += '0';

		printf("%s", soundex.c_str());
	}
	printf("\n");
	for(int i=0; i < 19; i++)
		printf(" ");
	printf("END OF OUTPUT\n");
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