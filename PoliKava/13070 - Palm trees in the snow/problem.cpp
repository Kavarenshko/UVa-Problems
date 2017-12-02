#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

constexpr int MAX_INDEX = 100000;
int v[MAX_INDEX];

int main()
{
	int tc;
	deque<ii> q;
	scanf("%d", &tc);

	while(tc--)
	{
		//printf("\n\nNEW TEST CASE\n\n");

		int kg, vsize, taken=0, c_max=0;
		q.clear();

		scanf("%d %d", &kg, &vsize);

		for(int i=0; i < vsize; i++)
			scanf("%d", &v[i]);

		for(int i=vsize-1; i >= 0; i--)
		{
			//printf("\nAnalyzing element %d...", i);
			int elem = v[i];

			if (q.size() == 0)
			{
				//printf("\n  > queue is empty, adding.");
				q.push_front({i, 1});
				if (elem >= kg)
					taken++;
				c_max = 1;
				continue;
			}

			if (elem >= kg) // this tree stands up, at most 5
			{
				//printf("\n  > tree standing, ");
				if (taken < 5)
				{
					//printf("taken < 5 (score = %d)", q.front().second+1);
					q.push_front({i, q.front().second+1});
					taken++;
				}
				else
				{
					//printf("taken is equal to 5,");
					while(1)
					{
						int ind = q.back().first;
						q.pop_back();
						//printf("\n    > removed index %d", ind);
						if (v[ind] >= kg) // search finished
							break;
					}
					//printf("\n  -> new element has score %d, taken is = 5", (q.back().first - i + 1));
					q.push_front({i, (q.back().first - i + 1)});
					taken = 5;
				}
			}
			else
			{
				//printf("\n  > not standing, ");
				if (v[i+1] >= kg)
				{
					//printf("adding with score %d", q.front().second+1);
					q.push_front({i, q.front().second+1});
				}
				else
				{
					//printf("updating previous score to %d", q.front().second+1);
					q.front().second++;
				}
			}
			c_max = max(c_max, q.front().second);
			//printf("\n(%d) current max is %d\n-\n", i, c_max);
		}
		printf("%d\n", c_max);
	}

	return EXIT_SUCCESS;
}