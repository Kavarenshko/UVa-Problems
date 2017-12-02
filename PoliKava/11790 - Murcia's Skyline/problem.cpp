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

int N;
int inc_width, dec_width;
vi dp_inc, dp_dec;
vii B;

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		print("\n\nTEST CASE - - - - - - -\n\n");
		scanf("%d", &N);

		B.clear();
		B.assign(N, {-1,-1});
		dp_inc.clear();
		dp_inc.assign(N, 0);
		dp_dec.clear();
		dp_dec.assign(N, 0);
		inc_width = -1;
		dec_width = -1;

		FOR(i, N)
			scanf("%d", &(B[i].first));
		FOR(i, N)
		{
			scanf("%d", &(B[i].second));
			//dp_inc[i] = B[i].second;
			//dp_dec[i] = B[i].second;
		}

		dp_inc[N-1] = B[N-1].second;
		dp_dec[N-1] = B[N-1].second;
		for(int i=N-2; i >= 0; i--)
		{
			for(int j=i+1; j < N; j++)
			{
				if (B[i].first < B[j].first)
				{
					dp_inc[i] = max(dp_inc[i], dp_inc[j]);
				}
				if (B[i].first > B[j].first)
				{
					dp_dec[i] = max(dp_dec[i], dp_dec[j]);
				}
			}
			dp_inc[i] += B[i].second;
			dp_dec[i] += B[i].second;
			print("\nIndex %d:", i);
			print("\n  > inc : %d with width %d", dp_inc[i], dp_inc[i]);
			print("\n  > dec : %d with width %d", dp_dec[i], dp_dec[i]);
		}
		int inc_max = 0;
		int dec_max = 0;
		FOR(i, N)
		{
			inc_max = max(inc_max, dp_inc[i]);
			dec_max = max(dec_max, dp_dec[i]);
		}
		printf("Case %d. ", tc);
		if (inc_max >= dec_max)
			printf("Increasing (%d). Decreasing (%d).\n", inc_max, dec_max);
		else
			printf("Decreasing (%d). Increasing (%d).\n", dec_max, inc_max);
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