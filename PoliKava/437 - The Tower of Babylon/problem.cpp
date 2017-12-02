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

int N;
vector<ii> v;
vi h;
map<ii, ll> dp;

bool fits(ii upper, ii lower)
{
	if (upper.first < lower.first && upper.second < lower.second)
		return true;
	if (upper.first < lower.second && upper.second < lower.first)
		return true;
	return false;
}

ll walk(unsigned ind)
{
	print("\nAnalyzing block (%d, %d) with height %d", v[ind].first, v[ind].second, h[ind]);
	if (dp.find(v[ind]) != dp.end())
	{
		print(", already calculated");
		return dp[v[ind]];
	}

	ll mvalue = h[ind];
	//unsigned mindex = -1;
	for(unsigned i=0; i < v.size(); i++)
	{
		print("\n  > (%d %d) comparing with (%d, %d), ", v[ind].first, v[ind].second, v[i].first, v[i].second);
		if (fits(v[i], v[ind]))
		{
			print("yes");
			mvalue = max(mvalue, h[ind] + walk(i));
		}
		else
			print("no");
	}
	print("\nTOTAL VALUE FOR BLOCK (%d, %d): %lld", v[ind].first, v[ind].second, mvalue);
	return dp[v[ind]] = mvalue;
}

int main()
{
	FOR1(tc, INF)
	{
		scanf("%d", &N);
		if (!N)
			break;

		v.clear();
		h.clear();
		dp.clear();

		print("\n\nTEST CASE - - - - - - -\n\n");

		FOR(i, N)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);

			v.push_back({a,b}); h.push_back(c);
			v.push_back({a,c}); h.push_back(b);
			v.push_back({b,c}); h.push_back(a);
		}

		ll tot = 0;
		FOR(i, N*3)
		{
			if (dp.find(v[i]) == dp.end())
				tot = max(tot, walk(i));
		}
		printf("Case %d: maximum height = %lld\n", tc, tot);
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