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

map<int, int> m;

int getNumber(const vi& v)
{
	int n = 0;
	FOR(i, 9)
		n += (v[i] << (8-i));
	return n;
}

int getNext(const vi& v)
{
	vi t(9);

	t[0] = v[1] + v[3];
	t[1] = v[0] + v[2] + v[4];
	t[2] = v[1] + v[5];
	t[3] = v[0] + v[4] + v[6];
	t[4] = v[1] + v[3] + v[5] + v[7];
	t[5] = v[2] + v[4] + v[8];
	t[6] = v[3] + v[7];
	t[7] = v[4] + v[6] + v[8];
	t[8] = v[5] + v[7];

	FOR(i, 9)
		t[i] %= 2;

	print(" -> ");
	FOR(i, 9)
		print("%d", t[i]);

	int tn = getNumber(t);
	print(" = %d", tn);

	if (m.find(tn) == m.end())
	{
		int val = getNext(t);
		m[tn] = val;
		return 1 + val;
	}
	else
		return 1 + m[tn];
}

void getNext(int n)
{
	vi v(9,0);
	print("\nAnalyzing ");
	FOR(i, 9)
	{
		if (n & (1 << (8-i)))
			v[i] = 1;
		print("%d", v[i]);
	}
	m[n] = getNext(v);
	print(", total is %d", m[n]);
}

int main()
{
	int N;
	int c;

	m[0] = -1;
	for(int i=1; i <= (1 << 9)-1; i++)
	{
		if (m.find(i) == m.end()) // process it
		{
			getNext(i);
		}
	}

	scanf("%d", &N);
	getchar();

	FOR1(tc, N)
	{
		string f = "";
		vi v(9);
		int a;

		getchar();
		FOR(i, 3)
		{
			string current;
			getline(cin, current);
			f += current;
		}

		FOR(i, 9)
			v[i] = (f[i] == '0'? 0 : 1);
		a = getNumber(v);
		printf("%d\n", m[a]);
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