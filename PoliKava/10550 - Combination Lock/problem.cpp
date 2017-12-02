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

int main()
{
	int pos,p1,p2,p3;
	while(1)
	{
		scanf("%d %d %d %d", &pos, &p1, &p2, &p3);
		if (!pos && !p1 && !p2 && !p3)
			break;
		int tot = 0;
		tot += 2*(9*40);
		if (pos > p1)
			tot += 9*(pos-p1);
		else
			tot += 9*40 - 9*(p1-pos);
		pos = p1;
		tot += (9*40);
		if (pos < p2)
			tot += 9*(p2-pos);
		else
			tot += 9*40 - 9*(pos-p2);
		pos = p2;
		if (p3 < pos)
			tot += 9*(pos-p3);
		else
			tot += 9*40 - 9*(p3-pos);
		printf("%d\n", tot);
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