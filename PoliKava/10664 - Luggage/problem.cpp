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

vi v;
int b1,b2;

bool walk(unsigned index)
{
	if (index == v.size())
		return (b1 == b2);

	b1 += v[index];
	if (walk(index+1))
		return true;
	b1 -= v[index];
	b2 += v[index];
	if (walk(index+1))
		return true;
	b2 -= v[index];
	return false;
}

int main()
{
	int TC;
	scanf("%d", &TC);
	getchar();

	FOR1(tc, TC)
	{
		v.clear();

		string s = "";
		while(1)
		{
			char c = getchar();
			if (c >= '0' && c <= '9')
				s += c;
			else
			{
				v.push_back(stoi(s));
				if (c == ' ')
					s = "";
				else if (c == '\n' || c == EOF)
					break;
				else
					*(int*)0 = 0;
			}
		}

		b1 = b2 = 0;
		b1 = v[0];
		if (walk(1))
			printf("YES\n");
		else
			printf("NO\n");
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