#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 100100;
constexpr int INF = 1000000000;

typedef long long ll;            // -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

struct segment
{
	int left;
	int right;
};

bool compareSegment(const struct segment &a, const struct segment &b)
{
	if (a.left < b.left)
		return true;
	else if (a.left == b.left)
	{
		if (a.right < b.right)
			return true;
	}
	return false;
}

struct segment a[MAX];
vector<struct segment> v;

int main()
{
	int TC,count;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		int M;

		count = 0;
		v.clear();

		if (tc)
			printf("\n");

		scanf("%d", &M);
		while(1)
		{
			struct segment curr;
			scanf("%d %d", &curr.left, &curr.right);
			if (!curr.left && !curr.right)
				break;
			if (curr.right <= 0)
				continue;
			a[count] = curr;
			count += 1;
		}
		FOR(i,count)
			print("\nIndex %d: (%d,%d)", i, a[i].left, a[i].right);
		sort(a, a+count, compareSegment);
		print("\n");
		FOR(i,count)
			print("\n*Index %d: (%d,%d)", i, a[i].left, a[i].right);

		int tp = 0;
		int newright = 0;
		int add_index = -INF;
		bool covered = false;
		for(int i=0; i <= count; i++)
		{
			if (i == count)
			{
				if (newright >= M)
				{
					v.push_back(a[add_index]);
					covered = true;
				}
				break;
			}

			if (a[i].left > tp)
			{
				if (newright == 0)
					break;
				else
				{
					tp = newright;
					newright = 0;
					v.push_back(a[add_index]);

					if (tp >= M)
					{
						covered = true;
						break;
					}
					else
					{
						i -= 1;
						continue;
					}
				}
			}
			else
			{
				if (a[i].right > newright)
				{
					add_index = i;
					newright = a[i].right;
				}
			}
		}

		if (covered)
		{
			printf("%lu\n", v.size());
			for(auto &s : v)
				printf("%d %d\n", s.left, s.right);
		}
		else
			printf("0\n");
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