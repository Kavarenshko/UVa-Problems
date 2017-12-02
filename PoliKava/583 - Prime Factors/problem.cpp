#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MAX_LIMIT = 100100;

vector< vector<unsigned> > primes(MAX_LIMIT);

void calculate()
{
	bitset<MAX_LIMIT> bs;
	bs.set();

	for(unsigned i=2; i < MAX_LIMIT; i++)
	{
		if (bs[i]) // prime number
		{
			if (primes[i].size() == 0)
				primes[i].push_back(i);
			for(unsigned j=2; i*j < MAX_LIMIT; j++)
			{
				unsigned m = i*j;
				if (bs[m]) // if (primes[m].size() == 0)
				{
					if (primes[j].size() == 0)
						continue;

					for(auto &fact : primes[i])
						primes[m].push_back(fact);
					for(auto &fact : primes[j])
					{
						primes[m].push_back(fact);
					}
					bs[m] = false;
				}
			}
		}
		sort(primes[i].begin(), primes[i].end());
	}
}

int main()
{
	ll N;
	calculate();

	/*for(int i=2; i < MAX_LIMIT; i++)
	{
		printf("\n%d: ", i);
		for(auto &f : primes[i])
		{
			printf("%d ", f);
		}
	}*/

	while(1)
	{
		if (scanf("%lld", &N) != 1)
			break;

		if (!N)
			break;

		printf("%lld = ", N);
		if (N < 0)
		{
			N *= -1;
			printf("-1 x ");
		}

		if (N >= MAX_LIMIT)
		{
			int ind = sqrt(N)+1;
			vector<int> f;
			while(1)
			{
				if (ind <= 2)
				{
					if (N % 2 == 0)
					{
						while (N % 2 == 0)
						{
							f.push_back(2);
							N /= 2;
						}
					}
					break;
				}

				if (N % ind == 0)
				{
					while(N % ind == 0)
					{
						N /= ind;
						for(auto &fact : primes[ind])
							f.push_back(fact);
					}
					ind = sqrt(N)+1;
				}
				else
					ind--;
			}
			if (N != 1)
				f.push_back(N);
			sort(f.begin(), f.end());

			for(unsigned i=0; i < f.size()-1; i++)
			{
				printf("%d x ", f[i]);
			}
			printf("%d\n", f.back());
		}
		else
		{
			for(unsigned i=0; i < primes[N].size()-1; i++)
			{
				printf("%d x ", primes[N][i]);
			}
			printf("%d\n", primes[N].back());
		}

	}

	return EXIT_SUCCESS;
}