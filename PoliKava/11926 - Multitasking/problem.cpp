#include <iostream>
#include <bitset>
#include <utility>
#include <vector>

#define MAX_N 1000000

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> ti; // interval

//bitset<MAX_N> bs;
vector<ti> v;
bool bs[MAX_N+1];

int main()
{
	int n,m;
	bool collision;

	while (1)
	{
		scanf("%d %d", &n, &m);

		if (!n && !m)
			break;

		collision = false;
		//bs.reset();
		fill(bs, bs+MAX_N+1, false);
		v.erase(v.begin(), v.end());

		for(int i=0; i < n; i++) // no interval
		{
			int start, end;
			scanf("%d %d", &start, &end);
			v.push_back(make_pair(make_pair(start, end), 0));
		}

		for(int i=0; i < m; i++)
		{
			int start, end, interval;
			scanf("%d %d %d", &start, &end, &interval);
			v.push_back(make_pair(make_pair(start, end), interval));
		}

		for(int i=0; i < v.size(); i++)
		{
			ti current = v[i];

			if (current.second) // interval
			{
				int k = 0;
				while (1)
				{
					for(int j = (current.first.first + k); j <= MAX_N && j < (current.first.second + k); j++)
					{
						if (bs[j])
						{
							collision = true;
							break;
						}
						bs[j] = true;
					}

					k += current.second;

					if (collision || k > MAX_N)
						break;
				}
			}
			else
			{
				for(int j=current.first.first; j < current.first.second; j++)
				{
					if (bs[j])
					{
						collision = true;
						break;
					}
					bs[j] = true;
				}
			}

			if (collision)
				break;
		}

		if (collision)
			printf("CONFLICT\n");
		else
			printf("NO CONFLICT\n");
		//break;
	}

	return EXIT_SUCCESS;
}