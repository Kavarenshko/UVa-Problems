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

int mvalue;
vi v, lis;

int walk(unsigned index, int cmax) // top-down
{
	if (index >= v.size())
		return 0;
	if (lis[index])
		return lis[index];

	for(unsigned i=index+1; i < v.size(); i++)
	{
		if (v[i] > v[index])
			lis[index] = max(lis[index], walk(i, v[i]));
	}
	mvalue = max(mvalue, lis[index] + 1);
	return lis[index] += 1;
}

int main()
{
	int TC, t;
	string s;
	scanf("%d", &TC);

	getchar();
	getline(cin, s);
	FOR(tc, TC)
	{
		if (tc)
			printf("\n");

		v.clear();
		lis.clear();
		mvalue = 0;
		while(1)
		{
			if (!getline(cin, s)) // EOF
				break;

			print("\n*%s", s.c_str());
			if (s == "" || s == " " || s == "\n")
				break;
			sscanf(s.c_str(), "%d", &t);
			v.push_back(t);
			lis.push_back(0);
		}

		for(unsigned i=0; i < v.size(); i++)
		{
			if (lis[i] == 0) // not visited
				walk(i, 0);
		}

		printf("Max hits: %d\n", mvalue);

		int ctop = INF;
		for(unsigned i=0; i < v.size(); i++)
		{
			if (v[i] < ctop && lis[i] == mvalue)
			{
				printf("%d\n", v[i]);
				ctop = v[i];
				mvalue -= 1;
			}
			if (mvalue == 0)
				break;
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