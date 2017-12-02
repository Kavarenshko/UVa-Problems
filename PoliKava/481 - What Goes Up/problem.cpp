#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> li;

vector<li> v; // store original values
vector<ll> l; // lis vector
//vector<ll> m; // max solution
stack<ll> s;

int main()
{
	ll n, c_max;
	int c_score;

	while(scanf("%lld", &n) == 1)
		v.push_back({n, 1});

	l.push_back(v[0].first);
	//m.push_back(v[0].first);

	for(unsigned i=1; i < v.size(); i++)
	{
		ll temp = v[i].first;

		//printf("\nAnalyzing index %d, element %lld. ", i, temp);

		if (temp > l.back()) // new best solution
		{
			l.push_back(temp);
			v[i].second = l.size();
			//m = l;
		}
		else if (temp == l.back())
		{
			v[i].second = l.size();
			continue;
		}
		else
		{
			int index = lower_bound(l.begin(), l.end(), temp) - l.begin();
			v[i].second = index+1;
			l[index] = temp;
		}

		/*printf("Done, vector L:");
		for(auto &d : l)
			printf("\n  > %lld", d);*/
	}

	printf("%lu\n-\n", l.size());
	c_score = l.size();
	c_max = 0x7fffffff;

	for(int i=v.size()-1; i >= 0; i--)
	{
		if (v[i].second == c_score && v[i].first < c_max)
		{
			s.push(v[i].first);
			c_max = v[i].first;
			c_score--;

			if (!c_score)
				break;
		}
	}

	while(!s.empty())
	{
		printf("%lld\n", s.top());
		s.pop();
	}

	/*printf("%lu\n-\n", m.size());
	for(auto &d : m)
	{
		printf("%lld\n", d.first);
	}*/

	return EXIT_SUCCESS;
}