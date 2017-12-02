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

vector<ii> v;

int main()
{
	double K;

	while(1)
	{
		if (scanf("%lf", &K) != 1)
			break;

		v.clear();
		for(double y=K+1; y <= K*2; y++)
		{
			double f = y/K;
			f -= 1;
			//print("\n%lf : %lf, %lf", y, f, fmod(y, f));
			if (fmod(y, f) <= 0.00001 || fabs(fmod(y, f) - f) <= 0.00001)
				v.push_back({round(y/f), round(y)});
		}
		printf("%lu\n", v.size());
		for(auto el : v)
			printf("1/%d = 1/%d + 1/%d\n", static_cast<int>(K), el.first, el.second);
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