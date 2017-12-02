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

int P,C;
int mvalue, mangry;
vi vp, vc;
int dp_v, dp_c;

int main()
{
	int TC,temp;
	scanf("%d", &TC);

	FOR1(tc, TC)
	{
		scanf("%d %d", &P, &C);

		//set<int> tried;

		vp.clear();
		vc.clear();
		dp_v = dp_c = 0;

		FOR(i, P)
		{
			scanf("%d", &temp);
			vp.push_back(temp);
		}
		FOR(i, C)
		{
			scanf("%d", &temp);
			vc.push_back(temp);
		}

		sort(vp.begin(), vp.end());
		sort(vc.begin(), vc.end());

		mvalue = 0;
		mangry = P;

		if (P == 0)
		{
			printf("0 0\n");
			continue;
		}
		if (C == 0)
		{
			printf("%d 0\n", vp.back());
			continue;
		}

		int h_val, p_val = vp.size() - 1;
		for(unsigned i=0; i < vp.size(); i++)
		{
			/*if (tried.find(vp[i]) == tried.end())
				tried.insert(vp[i]);
			else
				continue;*/

			for(unsigned j=dp_c; j < vc.size(); j++)
			{
				if (vp[i] <= vc[j])
					break;
				dp_c += 1;
			}

			h_val = (p_val - i) + dp_c;

			if (h_val < mangry)
			{
				mvalue = vp[i];
				mangry = h_val;
			}
		}
		print("\nREACHED");
		for(unsigned i=0; i < vc.size(); i++)
		{
			/*if (tried.find(vc[i]) == tried.end())
				tried.insert(vc[i]);
			else
				continue;*/

			for(int j=vp.size()-dp_v-1; j >= 0; j--)
			{
				print("\n  > %d %d is ", i, j);
				if (vc[i] >= vp[j])
					break;
				print("ok");
				dp_v += 1;
			}

			h_val = i + dp_v;

			if (h_val < mangry)
			{
				mvalue = vc[i];
				mangry = h_val;
			}
		}
		printf("%d %d\n", mvalue, mangry);
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