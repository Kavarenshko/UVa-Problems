#include <iostream>

using namespace std;

struct frame
{
	int roll1;
	int roll2;
	int score;
	bool strike;
	bool spare;
};

int main()
{
	string testcase;
	frame fs[10 + 1];

	while(getline(cin, testcase)) // for each test case
	{
		if (testcase[0] == 'G') // Game Over
			break;

		for(int i=0; i < 11; i++)
		{
			fs[i].roll1 = -1;
			fs[i].roll2 = -1;
			fs[i].score = 0;
			fs[i].strike = false;
			fs[i].spare = false;
		}

		// input should not be malformed, I trust you, UVa!

		int frame = 0;
		int score = 0;

		for(int i=0; i < testcase.length(); i++)
		{
			char c = testcase[i];

			if (c == ' ') // safer than the previous version (check if index i is even)
				continue;
			
			if (c == '/') // 2nd roll
			{
				fs[frame].roll2 = 10 - fs[frame].roll1;
				fs[frame].spare = true;
				frame++;
			}
			else if (c == 'X')
			{
				if (frame == 10)
				{
					if (fs[10].roll1 == -1)
						fs[10].roll1 = 10;
					else
						fs[10].roll2 = 10;
				}
				else
				{
					fs[frame].roll1 = 10;
					fs[frame].strike = true;
					frame++;
				}
			}
			else
			{
				if (fs[frame].roll1 == -1)
					fs[frame].roll1 = (int)c - 48;
				else
				{
					fs[frame].roll2 = (int)c - 48;
					frame++;
				}
			}
		}

		for(int i=0; i < 11; i++)
		{
			fs[i].roll1 = max(0, fs[i].roll1);
			fs[i].roll2 = max(0, fs[i].roll2);
			//cout << "FRAME " << i+1 << ": " << fs[i].roll1 << "," << fs[i].roll2 << "\n";
		}

		for(int i=0; i < 9; i++)
		{
			score += fs[i].roll1 + fs[i].roll2;
			if (fs[i].spare)
			{
				if (i+1 <= 9)
				{
					score += fs[i+1].roll1;
				}
			}
			else if (fs[i].strike)
			{
				if (i+1 <= 9)
				{
					score += fs[i+1].roll1 + fs[i+1].roll2;
					if (fs[i+1].strike && (i+2) <= 10)
					{
						score += fs[i+2].roll1;
					}
				}
			}
			//cout << "Frame " << i+1 << ": " << score << "\n";
		}

		score += fs[9].roll1 + fs[9].roll2 + fs[10].roll1 + fs[10].roll2;

		cout << score << "\n";
	}
	return EXIT_SUCCESS;
}