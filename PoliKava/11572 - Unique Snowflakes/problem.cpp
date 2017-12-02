#include <iostream>
#include <algorithm>

#define MAX_SNOWFLAKES 1000000 + 1

using namespace std;

long s[MAX_SNOWFLAKES]; // unsigned as 0 <= snowflake <= 10^9
int l[MAX_SNOWFLAKES]; // mark the last position of the snowflake with value i at index i
int score[MAX_SNOWFLAKES];

int main()
{
	int t;

	scanf("%d\n", &t);

	while(t--) // for every test case
	{
		int n; // max 10^6
		int max_score = 0;

		fill(l, l+MAX_SNOWFLAKES, 0);
		fill(score, score+MAX_SNOWFLAKES, 0);
		scanf("%d\n", &n); // scan the array starting from n-1

		for(int i=0; i < n; i++)
		{
			scanf("%ld", &s[i]);
		}

		if (n == 0)
		{
			cout << "0\n";
			continue;
		}
		else if (n == 1)
		{
			cout << "1\n";
			continue;
		}

		score[n-1] = 1; // best
		l[s[n-1]] = n-1; // its index

		for(int i=n-2; i >= 0; i--)
		{
			if (l[s[i]])
			{
				score[i] = min(l[s[i]]-i, score[i+1]+1);
			}
			else
			{
				score[i] = score[i+1] + 1;
			}
			l[s[i]] = i;
			max_score = max(max_score, score[i]);
			//cout << "\nScore of index " << i << " (" << s[i] << ") is " << score[i];
		}

		cout << max_score << "\n";
	}

	return EXIT_SUCCESS;
}