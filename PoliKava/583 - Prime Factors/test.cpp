#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1)
	{
		int n;
		if (scanf("%d:", &n) != 1)
			break;

		while(n != 1)
		{
			int fact;
			scanf("%d", &fact);
			n /= fact;
		}
		printf("done");
	}
}