#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 50100;
constexpr int INF = -1;

int v[MAXN]; // at most one outgoing link
int score[MAXN];
bool visited[MAXN];

int dfs(int index)
{
	if (visited[index])
		return 0;

	visited[index] = true;
	score[index] = dfs(v[index]) + 1;
	visited[index] = false;
	return score[index];
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int k=1; k <= T; k++)
	{
		int N;
		int max_score = INF;
		int final_index = 1;
		scanf("%d", &N);

		for(int i=0; i < MAXN; i++)
		{
			visited[i] = false;
			score[i] = INF;
			v[i] = INF;
		}

		for(int i=0; i < N; i++)
		{
			int A,B;

			scanf("%d %d", &A, &B);
			v[A] = B;

			if (A == B)
				*(int*)0 = 0;
		}

		for(int i=1; i <= N; i++)
		{
			if (score[i] == INF)
				dfs(i);
		}

		for(int i=1; i <= N; i++)
		{
			if (score[i] > max_score)
			{
				max_score = score[i];
				final_index = i;
			}
		}

		printf("Case %d: %d\n", k, final_index);
	}

	return EXIT_SUCCESS;
}