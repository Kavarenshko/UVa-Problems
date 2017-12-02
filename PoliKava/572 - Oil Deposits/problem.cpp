#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int LIMIT = 101;
constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int N,M,sol;
bool visited[LIMIT][LIMIT];
vector<string> v;

bool isValid(int r, int c)
{
	if (r >= 0 && r < M && c >= 0 && c < N)
		return true;
	return false;
}

void walk(int r, int c)
{
	int ar[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int ac[] = {0, -1, -1, -1, 0, 1, 1, 1};

	visited[r][c] = true;

	for(int i=0; i < 8; i++)
	{
		int nr = r + ar[i];
		int nc = c + ac[i];

		if (isValid(nr, nc) && v[nr][nc] == '@' && visited[nr][nc] == false)
			walk(nr, nc);
	}
}

int main()
{
	string s;

	while(1)
	{
		//print("\n\n");
		cin >> M >> N;

		if (M == 0)
			break;

		sol = 0;
		v.clear();
		FOR(i, LIMIT)
			FOR(j, LIMIT)
				visited[i][j] = false;

		cin.get();
		for(int i=0; i < M; i++)
		{
			getline(cin, s);
			v.push_back(s);
		}

		for(int i=0; i < M; i++)
		{
			for(int j=0; j < N; j++)
			{
				if (visited[i][j])
					continue;

				if (v[i][j] == '@')
				{
					sol += 1;
					walk(i,j);
				}
			}
		}

		cout << sol << "\n";
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