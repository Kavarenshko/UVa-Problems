#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

map<unsigned long long, int> m;

int main()
{
	int n,maxPop,users;

	while(1)
	{
		scanf("%d", &n);

		if(!n)
			break;

		m.erase(m.begin(), m.end());
		maxPop = 0;
		users = 0;

		for(int i=0; i < n; i++)
		{
			vector<unsigned long long> v(5);
			unsigned long long s = 0;
			unsigned long long mulf = 1000000000000LL;

			for(int j=0; j < 5; j++)
				scanf("%llu", &v[j]);

			sort(v.begin(), v.end());

			for(int j=0; j < 4; j++)
			{
				//printf("%llu - ", v[j]);
				s += v[j] * mulf;
				mulf /= 1000;
				//printf("%llu\n", v[j]);
			}
			s += v[4];

			//printf("%llu\n", s);

			if (m.find(s) == m.end())
				m[s] = 1;
			else
				m[s] += 1;
		}

		for(auto it = m.begin(); it != m.end(); it++)
		{
			if ((*it).second > maxPop)
			{
				maxPop = (*it).second;
				users = maxPop;
			}
			else if ((*it).second == maxPop)
			{
				users += (*it).second;
			}

			//printf("%d\n", (*it).second);
		}
		
		printf("%d\n", users);
	}

	return EXIT_SUCCESS;
}