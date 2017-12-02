#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

inline void fastRead_int(int *a)
{
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}

int main()
{

	while (1)
	{
		int n;
		scanf("%d", &n);

		if(!n)
			break;

		v.erase(v.begin(), v.end());

		for(int i=0; i < n; i++)
		{
			int c;
			//scanf("%hd", &c);
			fastRead_int(&c);
			v.push_back(c);
		}

		sort(v.begin(), v.end());

		for(auto it = v.begin(); it < (v.end()-1); it++)
			printf("%d ", *it);
		printf("%d\n", v.back());
	}

	return EXIT_SUCCESS;
}