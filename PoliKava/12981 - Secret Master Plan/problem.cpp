#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for(int i=1; i <= tc; i++)
	{
		int a[4], b[4];
		bool found;

		scanf("%d", &a[0]);
		scanf("%d", &a[1]);
		scanf("%d", &a[3]);
		scanf("%d", &a[2]);

		scanf("%d", &b[0]);
		scanf("%d", &b[1]);
		scanf("%d", &b[3]);
		scanf("%d", &b[2]);

		for(int j=0; j < 4; j++)
		{
			found = true;
			for(int k=j; k < (j+4); k++)
			{
				if (a[k-j] != b[k%4])
					found = false;
			}
			if (found)
				break;
		}

		printf("Case #%d: ", i);
		if (found)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}

	return EXIT_SUCCESS;
}