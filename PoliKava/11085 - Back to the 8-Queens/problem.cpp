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

int a[8];
int mvalue;

bool isValid(int q1_r, int q1_c, int q2_r, int q2_c)
{
	if (q1_r == q2_r)
		return false;
	if (q2_r == q1_r + (q2_c - q1_c))
		return false;
	if (q2_r == q1_r - (q2_c - q1_c))
		return false;
	return true;
}

void walk(int ind, int val)
{
	if (ind == 8)
	{
		print("\n*SOLUTION FOUND %d* ", val);
		for(int i=0; i < 8; i++)
		{
			print("%d ", a[i]);
		}
		mvalue = min(mvalue, val);
		return;
	}

	print("\nAnalyzing queen n.%d with val %d", ind, val);

	for(int i=0; i < 8; i++)
	{
		if (a[ind] - i >= 0)
		{
			bool isOk = true;
			for(int j=0; j < ind; j++)
			{
				print("\n  - checking with queen %d...", j);
				if (!isValid(a[j], j, a[ind]-i, ind))
				{
					print("not ok");
					isOk = false;
				}
			}
			if (isOk)
			{
				a[ind] -= i;
				walk(ind+1, val+min(1,i));
				a[ind] += i;
			}
		}
		if (i == 0) continue;
		if (a[ind] + i < 8)
		{
			bool isOk = true;
			for(int j=0; j < ind; j++)
			{
				print("\n  + checking with queen %d...", j);
				if (!isValid(a[j], j, a[ind]+i, ind))
				{
					print("not ok");
					isOk = false;
				}
			}
			if (isOk)
			{
				a[ind] += i;
				walk(ind+1, val+min(1,i));
				a[ind] -= i;
			}
		}
	}
}

int main()
{
	FOR1(tc, INF)
	{
		if (scanf("%d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7]) != 8)
			break;

		for(int i=0; i < 8; i++)
			a[i] -= 1;

		mvalue = INF;
		walk(0,0);
		printf("Case %d: %d\n", tc, mvalue);
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