#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSIZE = 51;

typedef pair<int, int> ii;

int R,C;
vector<ii> avoid;

char turnLeft(char c)
{
	switch(c)
	{
		case 'N':
		{
			return 'W';
		}
		case 'W':
		{
			return 'S';
		}
		case 'S':
		{
			return 'E';
		}
		case 'E':
		{
			return 'N';
		}
		default:
		{
			return '\0';
		}
	}
}
char turnRight(char c)
{
	switch(c)
	{
		case 'N':
		{
			return 'E';
		}
		case 'W':
		{
			return 'N';
		}
		case 'S':
		{
			return 'W';
		}
		case 'E':
		{
			return 'S';
		}
		default:
		{
			return '\0';
		}
	}
}

bool isInGrid(int x, int y)
{
	if (x < 0 || x > R || y < 0 || y > C)
		return false;
	return true;
}

int main()
{
	int c_x, c_y;
	char direction;
	bool lost;
	scanf("%d %d", &R, &C);

	while(scanf("%d %d %c", &c_x, &c_y, &direction) == 3)
	{
		string orders;
		getchar(); // skip \n
		getline(cin, orders);

		lost = false;

		for(char &c : orders)
		{
			//printf("\nCurrent position (%d,%d,%c), order: %c", c_x, c_y, direction, c);
			if (c == 'F')
			{
				if (direction == 'N')
				{
					if (isInGrid(c_x, c_y+1))
					{
						c_y += 1;
						//printf("\n  > moving, new coords %d %d", c_x, c_y);
					}
					else
					{
						ii c_pos = {c_x, c_y};
						bool found = false;
						for(auto &pit : avoid)
						{
							if (pit == c_pos)
							{
								found = true;
								break;
							}
						}
						if (found) // ignore this order
							continue;
						else
						{
							avoid.push_back(c_pos);
							lost = true;
							//printf("\n package lost");
							break;
						}
					}
				}
				else if (direction == 'S')
				{
					if (isInGrid(c_x, c_y-1))
					{
						c_y -= 1;
						//printf("\n  > moving, new coords %d %d", c_x, c_y);
					}
					else
					{
						ii c_pos = {c_x, c_y};
						bool found = false;
						for(auto &pit : avoid)
						{
							if (pit == c_pos)
							{
								found = true;
								break;
							}
						}
						if (found) // ignore this order
							continue;
						else
						{
							avoid.push_back(c_pos);
							lost = true;
							//printf("\n package lost");
							break;
						}
					}
				}
				else if (direction == 'W')
				{
					if (isInGrid(c_x-1, c_y))
					{
						c_x -= 1;
						//printf("\n  > moving, new coords %d %d", c_x, c_y);
					}
					else
					{
						ii c_pos = {c_x, c_y};
						bool found = false;
						for(auto &pit : avoid)
						{
							if (pit == c_pos)
							{
								found = true;
								break;
							}
						}
						if (found) // ignore this order
							continue;
						else
						{
							avoid.push_back(c_pos);
							lost = true;
							//printf("\n package lost");
							break;
						}
					}
				}
				if (direction == 'E')
				{
					if (isInGrid(c_x+1, c_y))
					{
						c_x += 1;
						//printf("\n  > moving, new coords %d %d", c_x, c_y);
					}
					else
					{
						ii c_pos = {c_x, c_y};
						bool found = false;
						for(auto &pit : avoid)
						{
							if (pit == c_pos)
							{
								found = true;
								break;
							}
						}
						if (found) // ignore this order
							continue;
						else
						{
							avoid.push_back(c_pos);
							lost = true;
							//printf("\n package lost");
							break;
						}
					}
				}
			}
			else if (c == 'R')
			{
				direction = turnRight(direction);
			}
			else if (c == 'L')
			{
				direction = turnLeft(direction);
			}
			else
				*(int*)0 = 0;
		}

		printf("%d %d %c", c_x, c_y, direction);
		if (lost)
			printf(" LOST\n");
		else
			printf("\n");
	}

	return EXIT_SUCCESS;
}