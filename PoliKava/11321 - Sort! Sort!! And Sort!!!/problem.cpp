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

int N,M;
bool sortElements(int a, int b)
{
	int mod_a, mod_b;
	mod_a = a % M;
	mod_b = b % M;

	if (mod_a == mod_b)
	{
		bool even_a, even_b;
		if (a < 0)
		{
			if ((-a) % 2 == 0)
				even_a = true;
			else
				even_a = false;
		}
		else
		{
			if (a % 2 == 0)
				even_a = true;
			else
				even_a = false;
		}

		if (b < 0)
		{
			if ((-b) % 2 == 0)
				even_b = true;
			else
				even_b = false;
		}
		else
		{
			if (b % 2 == 0)
				even_b = true;
			else
				even_b = false;
		}

		if (even_a && even_b)
			return (a < b);
		if (!even_a && !even_b)
			return (a > b);
		if (!even_a)
			return true;
		return false;
	}
	else
	{
		return (mod_a < mod_b);
	}
}

int main()
{
	while(1)
	{
		vi nums;

		scanf("%d %d", &N, &M);
		printf("%d %d\n", N, M);

		if (!N && !M)
			break;

		FOR(i, N)
		{
			int t;
			scanf("%d", &t);
			nums.push_back(t);
		}

		sort(nums.begin(), nums.end(), sortElements);
		for(auto &el : nums)
			printf("%d\n", el);
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