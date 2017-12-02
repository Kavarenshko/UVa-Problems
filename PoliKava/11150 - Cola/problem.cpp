#include <iostream>
#include <algorithm>

#define MAXN 202

using namespace std;

int empty[MAXN + 1];
int score[MAXN + 1];

int getBottles(int e)
{
	int t, drank = 0, curr = e;

	drank += curr / 3;
	curr /= 3;

	t = e % 3 + drank;
	empty[e] = empty[t];

	if (t >= 3)
		return drank + getBottles(t);
	else
		return drank;
}

int main()
{
	int n;

	empty[0] = 0;
	empty[1] = 1;
	empty[2] = 2;

	for(int i=3; i <= 202; i++)
		score[i] = getBottles(i);

	while(scanf("%d", &n) == 1)
	{
		int r1 = n + score[n];
		int r2, r3, m;

		if (empty[n+1] >= 1)
			r2 = n + score[n+1];
		else
			r2 = 0;
		if (empty[n+2] >= 2)
			r3 = n + score[n+2];
		else
			r3 = 0;

		m = max(r1, max(r2, r3));
		printf("%d\n", m);
	}

	return EXIT_SUCCESS;
}