#include <iostream>

#define INVALID_N 0x7fffffff

using namespace std;

short m[4][4];

inline short squareRow(int r) { return r < 2? 0 : 2; }
inline short squareCol(int c) { return c < 2? 0 : 2; }

short insert(int r, int c) // check if there is a unique solution for the given cell
{
	bool s[5]; // for some reason the curly bracket initializer doesn't work
	int sr = squareRow(r);
	int sc = squareCol(c);
	int index = INVALID_N;

	for(int i=1; i <= 4; i++)
		s[i] = true;

	// row check
	for(int i=0; i < 4; i++)
	{
		if (i == r)
			continue;
		if (m[i][c])
			s[ m[i][c] ] = false; // can't be this number
	}

	// col check
	for(int i=0; i < 4; i++)
	{
		if (i == c)
			continue;
		if (m[r][i])
			s[ m[r][i] ] = false;
	}

	// subsquare check
	for(int i=sr; i < (2 + sr); i++)
	{
		for(int j=sc; j < (2 + sc); j++)
		{
			if (i == r && j == c)
				continue;
			if (m[i][j])
				s[ m[i][j] ] = false;
		}
	}

	for(int i=1; i <= 4; i++)
	{
		if (s[i])
		{
			if (index == INVALID_N)
				index = i;
			else
				return 0;
		}
	}

	if (index == INVALID_N)
		*(int*)0 = 0;

	//printf("Solution found for cell (%d,%d): %d", r+1, c+1, index); // if index is INVALID_N at this point then the given Sudoku is not solvable, which is impossible by assumptions
	return index;
}

int main()
{
	int tc, totalN;
	scanf("%d", &tc);

	for(int i=1; i <= tc; i++)
	{
		totalN = 0;

		for(int j=0; j < 4; j++) // read table
		{
			for(int k=0; k < 4; k++)
			{
				char c = getc(stdin);
				if (c == '\n')
				{
					k--;
					continue;
				}

				if (c == '*')
					m[j][k] = 0;
				else
				{
					m[j][k] = (int)(c-48);
					totalN++;
				}
			}
			//getc(stdin);
		}

		while(totalN != 16)
		{
			for(int j=0; j < 4; j++)
			{
				for(int k=0; k < 4; k++)
				{
					if (!m[j][k])
					{
						short res = insert(j,k);
						//printf("Solution found for cell (%d,%d): %d\n", j+1, k+1, res);
						if (res)
						{
							m[j][k] = res;
							totalN++;
						}
					}
				}
			}
		}

		printf("Case #%d:\n", i);
		for(int j=0; j < 4; j++)
		{
			for(int k=0; k < 4; k++)
			{
				printf("%d", m[j][k]);
			}
			printf("\n");
		}
		//break;
	}

	return EXIT_SUCCESS;
}