#include <iostream>
#include <string>
#include <algorithm>

#define MAX_ROWS 10
#define MAX_COLS 100
#define MAX_INT 0x7fffffff

using namespace std;

int r,c;
long m[MAX_ROWS][MAX_COLS];
long w[MAX_ROWS][MAX_COLS];

struct solution
{
	long score;
	int row;

	bool operator<(const struct solution& b) const
	{
		if (score < b.score)
			return true;
		else if (score == b.score)
		{
			// sort by lexicographic order
			return row < b.row? true : false;
		}
		return false;
	}
};

long walk(int pr, int pc)
{
	if (w[pr][pc] != MAX_INT) // already computed
		return w[pr][pc];

	if (pc == c-1) // end
	{
		w[pr][pc] = m[pr][pc];
		return w[pr][pc];
	}

	long s1 = walk((pr - 1 + r) % r, pc + 1);
	long s2 = walk(pr, pc + 1);
	long s3 = walk((pr + 1 + r) % r, pc + 1);

	w[pr][pc] = m[pr][pc] + min(min(s1, s2), s3);
	//printf("Weight of %d,%d is %ld\n", pr, pc, w[pr][pc]);
	return w[pr][pc];
}

string bestSolution(int pr, int pc)
{
	if (pc == c-1)
		return to_string(pr+1);

	solution a[3];

	a[0].score = w[(pr - 1 + r) % r][pc + 1];
	a[0].row = (pr - 1 + r) % r;

	a[1].score = w[pr][pc + 1];
	a[1].row = pr;

	a[2].score = w[(pr + 1 + r) % r][pc + 1];
	a[2].row = (pr + 1 + r) % r;

	sort(a, a+3);

	// printf("POINT %d,%d: %ld - %d\n", pr+1, pc+1, a[0].score, a[0].row+1);

	return to_string(pr+1) + " " + bestSolution(a[0].row, pc + 1);
}

int main()
{
	long min_score;
	string best;
	int best_row;

	while(scanf("%d %d", &r, &c) != EOF) // for every test case
	{
		// /*
		//printf("\n");
		for(int i=0; i < MAX_ROWS; i++)
		{
			for(int j=0; j < MAX_COLS; j++)
			{
				m[i][j] = MAX_INT;
				w[i][j] = MAX_INT;
			}
		}
		// */
		min_score = MAX_INT;
		best = "";
		best_row = MAX_INT;

		for(int i=0; i < r; i++)
			for(int j=0; j < c; j++)
				scanf("%ld", &m[i][j]);
		
		if (r == 1)
		{
			min_score = 0;
			for(int i=0; i < c; i++)
			{
				min_score += m[0][i];
				best += "1 ";
			}
			best.pop_back();
			printf("%s\n%ld\n", best.c_str(), min_score);
			continue;
		}

		if (c == 1)
		{
			for(int i=0; i < r; i++)
			{
				if (m[i][0] < min_score) // preserves lexicographic order
				{
					min_score = m[i][0];
					best_row = i+1;
				}
			}
			printf("%s\n%ld\n", to_string(best_row).c_str(), min_score);
			continue;
		}

		// r,c > 1

		for(int i=0; i < r; i++)
		{
			long current_score = walk(i,0);

			if (current_score < min_score) // check lexicographic order
			{
				min_score = current_score;
				best_row = i;
			}
		}

		best = bestSolution(best_row, 0);
		printf("%s\n%ld\n", best.c_str(), min_score);
	}

	return EXIT_SUCCESS;
}