#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> pq;
	int ugly_nth = 0;
	int current_n = 1;
	set<int>::iterator it;

	pq.insert(1);

	while (1)
	{
		it = pq.lower_bound(current_n);
		current_n = *it; pq.erase(it);
		ugly_nth++;

		if (ugly_nth == 1500)
		{
			printf("The 1500'th ugly number is %d.\n", current_n);
			break;
		}

		pq.insert(current_n * 2);
		pq.insert(current_n * 3);
		pq.insert(current_n * 5);
	}

	return EXIT_SUCCESS;
}