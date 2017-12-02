#include <iostream>
#include <algorithm>

#define MAX_CHARS 256

using namespace std;

long long a[MAX_CHARS];

int main()
{
	int tc;
	long long price;
	scanf("%d\n", &tc);

	while(tc--)
	{
		int k,m;

		price = 0;
		fill(a, a+MAX_CHARS, 0);

		scanf("%d\n", &k);

		for(int i=0; i < k; i++)
		{
			char c;
			long long val;

			scanf("%c %lld\n", &c, &val);
			a[c+128] = val;
		}

		scanf("%d\n", &m);

		for(int i=0; i < m; i++)
		{
			char* s = NULL;
			size_t b = 0;
			int bytes = getline(&s,&b,stdin);

			for(int j=0; j < bytes; j++)
			{
				if (s[j] == '\n')
					continue;
				price += a[s[j]+128];
			}
		}
		printf("%.2Lf$\n", (long double)(price/100.0));
	}

	return EXIT_SUCCESS;
}