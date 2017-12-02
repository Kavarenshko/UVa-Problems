#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long h, o;

	while(scanf("%llu %llu", &h, &o) == 2)
	{
		if (o >= h)
			printf("%llu\n", o-h);
		else
			printf("%llu\n", h-o);
	}

	return EXIT_SUCCESS;
}