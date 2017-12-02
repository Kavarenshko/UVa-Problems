#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr long long MAX = 9999999999LL;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

bool noRepeating(long long a)
{
	bool v[10] = {false};

	string s = to_string(a);
	for(auto &c : s)
	{
		if (v[c-'0'])
			return false;
		v[c-'0'] = true;
	}
	return true;
}

int getNext(string a)
{
	//print("\nCall at getNext with string %s", a.c_str());
	for(int i=a.size()-1; i > 0; i--)
	{
		for(int j=i-1; j >= 0; j--)
		{
			if (a[j] == a[i])
			{
				if (a[i] == '9')
					return getNext(to_string(stoll(a) + static_cast<int>(pow(10.0, a.size()-1-i))));
				a[i] += 1;
				return getNext(a);
			}
		}
	}
	return stoll(a);
}

int getNext(long long a)
{
	return getNext(to_string(a+1));
}

int main()
{
	int TC;
	scanf("%d", &TC);

	FOR(tc, TC)
	{
		long long N;
		scanf("%lld", &N);

		if (tc)
			printf("\n");

		long long mult = 1;
		while(1)
		{
			//print("\nCurrent mult: %lld", mult);
			if (noRepeating(mult))
			{
				long long f = N * mult;
				//print("\n%lld", mult);
				if (f > MAX)
				{
					//print(", leaving");
					break;
				}
				if (noRepeating(f))
					printf("%lld / %lld = %lld\n", f, mult, N);
			}
			mult = getNext(mult);
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