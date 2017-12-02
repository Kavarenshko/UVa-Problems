#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int MAX = 100;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int R,C;
bool m[MAX][MAX];
bool v[MAX][MAX];

bool isValid(int r, int c)
{
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return m[r][c];
}

int walk(int r, int c)
{
	int ar[] = {-1,-1,0,1,1,1,0,-1};
	int ac[] = {0,-1,-1,-1,0,1,1,1};

	int tot = 1;
	v[r][c] = true;
	for(int i=0; i < 8; i++)
	{
		if (isValid(r+ar[i], c+ac[i]))
		{
			if (!v[r+ar[i]][c+ac[i]])
				tot += walk(r+ar[i], c+ac[i]);
		}
	}
	return tot;
}

int main()
{
	int TC;
	scanf("%d", &TC);

	getchar(); getchar();
	FOR(tc, TC)
	{
		R = 0;
		C = INF;

		if (tc)
			printf("\n");
		
		while(1)
		{
			string s;
			getline(cin, s);

			if (s.size() == 0)
				break;

			if (s[0] == 'W' || s[0] == 'L')
			{
				C = (int)s.size();
				FOR(i,C)
					m[R][i] = (s[i] == 'W');
				R += 1;
			}
			else
			{
				int r,c;

				FOR(i,R)
					FOR(j,C)
						v[i][j] = false;
				sscanf(s.c_str(), "%d %d", &r, &c);
				printf("%d\n", walk(r-1,c-1));
			}
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