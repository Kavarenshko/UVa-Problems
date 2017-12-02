#include <iostream>

using namespace std;

int main()
{
	int t;

	cin >> t;
	for(int j=1; j <= t; j++)
	{
		int n, max=1;
		cin >> n;

		for(int i=0; i < n; i++)
		{
			int temp_speed;
			cin >> temp_speed;
			if (temp_speed > max)
				max = temp_speed;
		}
		cout << "Case " << j << ": " << max << "\n";
	}
	
	return EXIT_SUCCESS;
}