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

int sPow(unsigned ex)
{
	if (ex == 1)
		return 2;
	else
		return 2*sPow(ex-1);
}

int main()
{
	string cnum;
	while(1)
	{
		getline(cin, cnum);
		if (cnum == "0" || cnum == "0\n")
			break;
		print("\nCnum: %s*", cnum.c_str());

		int csum = 0;
		//unsigned s = cnum.size();
		for(unsigned i=0; i < cnum.size(); i++)
		{
			csum += (cnum[i] - '0') * (sPow(cnum.size()-i)-1);
			print("\n  > %d", csum);
		}
		printf("%d\n", csum);
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