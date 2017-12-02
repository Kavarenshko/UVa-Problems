#include <iostream>
#include <algorithm>

#define MAX_INT 0x7fffffff

using namespace std;

int main()
{
	unsigned long total_brown, total_green, total_clear;
	unsigned long m[3][3];
	unsigned long s[3][3]; // cost

	while(scanf("%lu %lu %lu %lu %lu %lu %lu %lu %lu\n", &m[0][0], &m[0][1], &m[0][2], &m[1][0], &m[1][1], &m[1][2], &m[2][0], &m[2][1], &m[2][2]) != EOF)
	{
		string disp = "BCG";
		string best_disp = "BCG";
		long min_cost = MAX_INT;

		total_brown = m[0][0] + m[1][0] + m[2][0];
		total_green = m[0][1] + m[1][1] + m[2][1];
		total_clear = m[0][2] + m[1][2] + m[2][2];

		for(int i=0; i < 3; i++)
		{
			for(int j=0; j < 3; j++)
			{
				if (i == 0)
					s[i][j] = total_brown - m[j][i];
				else if (i == 1)
					s[i][j] = total_green - m[j][i];
				else
					s[i][j] = total_clear - m[j][i];

				//cout << "S(" << i << "," << j << "): " << s[i][j] << "\n";
			}
		}

		do
		{
			long local_cost = 0;
			for(int i=0; i < 3; i++)
			{
				if (disp[i] == 'B')
					local_cost += s[0][i];
				else if (disp[i] == 'C')
					local_cost += s[2][i];
				else
					local_cost += s[1][i];
			}

			if (local_cost < min_cost)
			{
				min_cost = local_cost;
				best_disp = disp;
				//cout << "\nNew best: " << best_disp << ", " << min_cost << "\n";
			}
			/*else
				cout << "\nNOT best: " << disp << ", " << local_cost << "\n";*/

		}while(next_permutation(disp.begin(), disp.end()));

		cout << best_disp << " " << min_cost << "\n";
	}

	return EXIT_SUCCESS;
}