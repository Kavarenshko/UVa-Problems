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
	vi v, lds;
	FOR1(tc, INF)
	{
		v.clear();
		lds.clear();
		while(1)
		{
			int a;
			scanf("%d", &a);
			if (a == -1)
				break;
			v.push_back(a);
			lds.push_back(0);
		}
		if (v.size() == 0)
			break;
		if (tc > 1)
			printf("\n");
		printf("Test #%d:\n", tc);

		int mvalue = -1;
		for(int i=v.size()-1; i >= 0; i--)
		{
			for(unsigned j=i+1; j < v.size(); j++)
			{
				if (v[i] >= v[j])
					lds[i] = max(lds[i], lds[j]);
			}
			lds[i] += 1;
			mvalue = max(mvalue, lds[i]);
		}
		printf("  maximum possible interceptions: %d\n", mvalue);
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