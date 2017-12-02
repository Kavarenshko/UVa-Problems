#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSIZE = 101;

constexpr int WATER = 0;
constexpr int UNVISITED = 1;
constexpr int VISITED = 2;

typedef pair<int, int> ii;

int R,C,M,N,W;
int even, odd;
int m[MAXSIZE][MAXSIZE];

int rs[4] = {1,1,-1,-1};
int cs[4] = {1,-1,1,-1};

bool isValid(int r, int c)
{
	if (r >= 0 && c >= 0 && r < R && c < C && m[r][c] != WATER)
		return true;
	return false;
}

void dfs(int r, int c)
{
	set<int> added;
	int count = 0;
	m[r][c] = VISITED;

	//printf("\nVisiting %d,%d...", r, c);

	for(int i=0; i < 4; i++)
	{
		int t_r = r + (rs[i]*M);
		int t_c = c + (cs[i]*N);

		//printf("\n  > %d,%d - analyzing %d,%d...", r, c, t_r, t_c);

		if (isValid(t_r, t_c) && added.find(t_r*R+t_c) == added.end())
		{
			//printf("fine");
			added.insert(t_r*R+t_c);
			count++;
			if (m[t_r][t_c] == UNVISITED)
				dfs(t_r, t_c);
		}

		t_r = r + (rs[i]*N);
		t_c = c + (cs[i]*M);

		//printf("\n SWAP\n  > %d,%d - analyzing %d,%d...", r, c, t_r, t_c);

		if (isValid(t_r, t_c) && added.find(t_r*R+t_c) == added.end())
		{
			//printf("fine");
			added.insert(t_r*R+t_c);
			count++;
			if (m[t_r][t_c] == UNVISITED)
				dfs(t_r, t_c);
		}
	}

	if (count % 2 == 0 || count % 2 == 2)
		even++;
	else
		odd++;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int k=1; k <= T; k++)
	{
		even = 0;
		odd = 0;

		scanf("%d %d %d %d %d", &R, &C, &M, &N, &W);

		for(int i=0; i < MAXSIZE; i++)
			for(int j=0; j < MAXSIZE; j++)
				m[i][j] = UNVISITED;

		for(int i=0; i < W; i++)
		{
			int w_r, w_c;
			scanf("%d %d", &w_r, &w_c);
			
			m[w_r][w_c] = WATER;
		}

		dfs(0,0);

		printf("Case %d: %d %d\n", k, even, odd);
	}

	return EXIT_SUCCESS;
}