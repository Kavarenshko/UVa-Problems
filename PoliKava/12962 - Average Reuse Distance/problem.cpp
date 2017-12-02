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

double customRound(double n) { return round(n*10000) / 10000; }

map<char, ii> m;

int main()
{
	while(1)
	{
		string curr_str;
		getline(cin, curr_str);

		if (curr_str == "0" || curr_str == "0\n")
			break;

		int ref_count = 0;
		int transitions = 0;
		m.clear();

		for(unsigned i=0; i < curr_str.size(); i++)
		{
			print("\nAnalyzing char '%c' at index %d...", curr_str[i], i);

			if (m.find(curr_str[i]) == m.end()) // new char
			{
				for(auto &el : m)
					el.second.first += 1;
				m[curr_str[i]] = {0,i};
			}
			else
			{
				int cindex = m[curr_str[i]].second;
				for(auto &el : m)
				{
					if (el.second.second > cindex)
						el.second.first += 1;
				}
				transitions += 1;
				ref_count += m[curr_str[i]].first;
				m[curr_str[i]].first = 0;
				m[curr_str[i]].second = i;
			}
			for(auto &el : m)
			{
				print("\n  > %c : {%d,%d}", el.first, el.second.first, el.second.second);
			}
		}

		print("\nFinal values: %d %d", ref_count, transitions);

		if (transitions == 0)
			printf("NaN\n");
		else
			printf("%.4lf\n", customRound( (double)ref_count / (double)transitions ));
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