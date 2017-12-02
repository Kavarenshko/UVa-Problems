#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	for(unsigned long long a = 1; a <= 2000; a++)
	{
		for(unsigned long long b = a; a + b <= 2000; b++)
		{
			for(unsigned long long c = b; a + b + c + c <= 2000; c++)
			{
				unsigned long long sum = a + b + c;
				unsigned long long mul = a * b * c;

				if (mul == 1000000)
					continue;

				unsigned long long d = (1000000 * sum) / (mul - 1000000); 

				if (d < c)
					continue;
				if (sum + d > 2000)
					continue;

				if (1000000*(sum+d) == mul*d)
				{
					printf("%.2lf %.2lf %.2lf %.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
				}
			}
		}
	}
	
	return EXIT_SUCCESS;
}
