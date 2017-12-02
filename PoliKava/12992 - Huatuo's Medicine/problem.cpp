#include <iostream>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for(int i=1; i <= tc; i++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", i, (n*2)-1);
	}

	return EXIT_SUCCESS;
}