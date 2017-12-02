#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_KEBAB = 10000010;
vector<ull> primes;

void getPrimes()
{
	bitset<MAX_KEBAB> bs;
	bs.set();

	for(int i=2; i < MAX_KEBAB; i++)
	{
		if (bs[i])
		{
			for(int j=2;;j++)
			{
				if (i*j >= MAX_KEBAB)
					break;
				bs.reset(i*j);
			}
			primes.push_back(i);
		}
	}
}

int main()
{
	getPrimes();
	while(1)
	{
		unsigned long long n;
		unsigned long long counter = 0;
		scanf("%llu", &n);

		if (n == 1)
			break;

		for(auto &d : primes) // first check all prime numbers
		{
			if (n == 1)
				break;
			while(n % d == 0)
			{
				//printf("Div: %llu\n", d);
				n /= d;
				counter++;
			}
		}

		if (n != 1)
			counter++;

		printf("%llu\n", counter);
	}
	return EXIT_SUCCESS;
}