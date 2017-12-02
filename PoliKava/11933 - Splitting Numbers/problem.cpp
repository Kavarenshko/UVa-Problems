#include <iostream>

using namespace std;

int main()
{
	unsigned long n,a,b;
	bool sign;

	while(scanf("%lu",&n) && n)
	{
		a = 0;
		b = 0;
		sign = true;

		for(int i=0; i < 32; i++)
		{
			if (n & (1 << i))
			{
				if (sign)
					a |= (1 << i);
				else
					b |= (1 << i);
				sign = !sign;
			}
		}
		cout << a << " " << b << "\n";
	}

	return EXIT_SUCCESS;
}