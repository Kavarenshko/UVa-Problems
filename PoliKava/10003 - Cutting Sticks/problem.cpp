#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX_CUTS = 51;
constexpr int MAX_LENGTH = 1001;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef tuple<int, int, int> status;

void print(const char* msg, ...);

string s;

int main()
{
	while(1)
	{
		getline(cin, s);
		if (s == ".")
			break;

		int len = s.size();
		for(int i=len; i >= 1; i--)
		{
			bool loop_found = false;
			if ((len % i) == 0) // feasible
			{
				int counter = 1;
				int individual_length = len / i;
				size_t prev_cindex, cindex;

				loop_found = true;
				string curr = s.substr(0, individual_length);
				cindex = curr.size();
				prev_cindex = cindex;

				while((cindex = s.find(curr, cindex)) != string::npos)
				{
					if (cindex != prev_cindex)
					{
						loop_found = false;
						break;
					}
					cindex += curr.size();
					prev_cindex = cindex;
					counter += 1;
				}

				if (counter != i)
					loop_found = false;
			}

			if (loop_found)
			{
				printf("%d\n", i);
				break;
			}
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