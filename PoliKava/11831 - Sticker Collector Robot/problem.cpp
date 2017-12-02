#include <bits/stdc++.h>

using namespace std;

constexpr int MAXSIZE = 101;
constexpr short WALL = 0;
constexpr short FREE = 1;
constexpr short STICKER = 2;

typedef pair<int, int> ii;

short m[MAXSIZE][MAXSIZE];
int N,M,S;

char rotate(char curr, char dir)
{
	if (curr == 'N')
	{
		if (dir == 'D')
			return 'L';
		else if (dir == 'E')
			return 'O';
	}
	else if (curr == 'O')
	{
		if (dir == 'D')
			return 'N';
		else if (dir == 'E')
			return 'S';
	}
	else if (curr == 'S')
	{
		if (dir == 'D')
			return 'O';
		else if (dir == 'E')
			return 'L';
	}
	else if (curr == 'L')
	{
		if (dir == 'D')
			return 'S';
		else if (dir == 'E')
			return 'N';
	}

	*(int*)0 = 0;
	return '\0';
}

ii moveRobot(ii pos, char dir)
{
	int c_x = pos.first;
	int c_y = pos.second;

	if (dir == 'N')
	{
		if (c_x > 0 && m[c_x-1][c_y] != WALL)
			c_x -= 1;
	}
	else if (dir == 'O')
	{
		if (c_y > 0 && m[c_x][c_y-1] != WALL)
			c_y -= 1;
	}
	else if (dir == 'S')
	{
		if (c_x < N-1 && m[c_x+1][c_y] != WALL)
			c_x += 1;
	}
	else if (dir == 'L')
	{
		if (c_y < M-1 && m[c_x][c_y+1] != WALL)
			c_y += 1;
	}

	return {c_x, c_y};
}

int main()
{

	while(1)
	{
		int collected = 0;
		string orders;
		ii curr_pos;
		char d;

		scanf("%d %d %d", &N, &M, &S);

		if (!N && !M && !S)
			break;

		for(int i=0; i < MAXSIZE; i++)
			for(int j=0; j < MAXSIZE; j++)
				m[i][j] = WALL;

		getchar(); // \n

		for(int i=0; i < N; i++)
		{
			for(int j=0; j < M; j++)
			{
				char c = getchar();

				if (c == '.')
					m[i][j] = FREE;
				else if (c == '*')
					m[i][j] = STICKER;
				else if (c == '#')
					m[i][j] = WALL;
				else if (c == '\n')
					*(int*)0 = 0;
				else // letter
				{
					curr_pos.first = i;
					curr_pos.second = j;
					d = c;
					m[i][j] = FREE;
				}
			}
			getchar();
		}

		getline(cin, orders);

		if (orders.length() != S)
			*(int*)0 = 0;

		for(int i=0; i < S; i++) // for every order
		{
			if (orders[i] == 'D' || orders[i] == 'E')
				d = rotate(d, orders[i]);
			else
			{
				curr_pos = moveRobot(curr_pos, d);
				if (m[curr_pos.first][curr_pos.second] == STICKER)
				{
					collected++;
					m[curr_pos.first][curr_pos.second] = FREE;
				}
			}
		}
		printf("%d\n", collected);
	}

	return EXIT_SUCCESS;
}