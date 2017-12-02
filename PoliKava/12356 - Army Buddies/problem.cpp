#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSOLDIERS = 100002;
constexpr int INF = 0x7fffffff;

typedef pair<int, int> ii;

int S,B;
vector<ii> a(MAXSOLDIERS);

inline bool isAlive(ii p) { return (!p.first && !p.second); }

int main()
{
	while(1)
	{
		scanf("%d %d", &S, &B);

		if (!S && !B)
			break;

		a[0] = {INF, INF};
		for(int i=1; i <= S; i++)
		{
			a[i] = {0, 0};
		}
		a[S+1] = {INF, INF};

		for(int i=0; i < B; i++)
		{
			int s1, s2, left_value, right_value;
			scanf("%d %d", &s1, &s2);

			left_value = s2-s1+1;
			while(a[s2-left_value].first != 0 && a[s2-left_value].first != INF)
			{
				left_value += a[s2-left_value].first;
			}
			a[s2].first = left_value;

			if (a[s2-left_value].first == INF)
				printf("* ");
			else
				printf("%d ", s2-left_value);

			right_value = s2-s1+1;
			while(a[s1+right_value].second != 0 && a[s1+right_value].second != INF)
			{
				right_value += a[s1+right_value].second;
			}
			a[s1].second = right_value;

			if (a[s1+right_value].second == INF)
				printf("*\n");
			else
				printf("%d\n", s1+right_value);
		}
		printf("-\n");
	}

	return EXIT_SUCCESS;
}