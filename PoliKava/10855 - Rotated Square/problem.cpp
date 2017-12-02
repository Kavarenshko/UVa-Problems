#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;

typedef long long ll;            // –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (19 digits)
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int main()
{
	int N,M;
	vector<string> big;
	vector<string> small;
	vector<string> supp;
	vector< vector<vi> > bq;

	while(1)
	{
		int count;

		scanf("%d %d", &N, &M);
		if (!N && !M)
			break;
		getchar();

		bq.assign(N, vector<vi>());
		for(auto &p : bq)
			p.assign(N, vi());

		big.assign(N, "");
		FOR(i, N)
			getline(cin, big[i]);

		small.assign(M, "");
		FOR(i, M)
			getline(cin, small[i]);

		print("\n\nTEST CASE - - - - - - -\n\n");

		count = 0;
		for(auto &p : bq)
			for(auto &el : p)
				el.clear();
		FOR(i, N)
		{
			FOR(j, N)
			{
				if (big[i][j] == small[0][0] && i <= N-M && j <= N-M)
				{
					if (M == 1)
						count += 1;
					else
						bq[i][j+1].push_back(1);
				}

				print("\nCell (%d, %d): ", i, j);
				for(auto &el : bq[i][j])
				{
					print("\n  > %d: ", el);
					int r_index, c_index;

					r_index = el / M;
					c_index = el % M;
					print("%c vs %c", big[i][j], small[r_index][c_index]);

					if (big[i][j] == small[r_index][c_index])
					{
						print(" OK, ");
						if (el+1 == M*M)
						{
							print("finished.");
							count += 1;
							continue;
						}

						if ((el+1) % M == 0)
						{
							print("added next row at (%d, %d)", i+1, j-c_index);
							bq[i+1][j-c_index].push_back(el+1);
						}
						else
						{
							print("added at (%d, %d)", i, j+1);
							bq[i][j+1].push_back(el+1);
						}
					}
				}
			}
		}

		printf("%d ", count);
		supp = small;
		for(int i=0; i < M; i++)
			for(int j=0; j < M; j++)
				supp[i][j] = small[M-j-1][i];
		small = supp;

		count = 0;
		for(auto &p : bq)
			for(auto &el : p)
				el.clear();
		FOR(i, N)
		{
			FOR(j, N)
			{
				if (big[i][j] == small[0][0] && i <= N-M && j <= N-M)
				{
					if (M == 1)
						count += 1;
					else
						bq[i][j+1].push_back(1);
				}

				print("\nCell (%d, %d): ", i, j);
				for(auto &el : bq[i][j])
				{
					print("\n  > %d: ", el);
					int r_index, c_index;

					r_index = el / M;
					c_index = el % M;
					print("%c vs %c", big[i][j], small[r_index][c_index]);

					if (big[i][j] == small[r_index][c_index])
					{
						print(" OK, ");
						if (el+1 == M*M)
						{
							print("finished.");
							count += 1;
							continue;
						}

						if ((el+1) % M == 0)
						{
							print("added next row at (%d, %d)", i+1, j-c_index);
							bq[i+1][j-c_index].push_back(el+1);
						}
						else
						{
							print("added at (%d, %d)", i, j+1);
							bq[i][j+1].push_back(el+1);
						}
					}
				}
			}
		}

		printf("%d ", count);
		supp = small;
		for(int i=0; i < M; i++)
			for(int j=0; j < M; j++)
				supp[i][j] = small[M-j-1][i];
		small = supp;

		count = 0;
		for(auto &p : bq)
			for(auto &el : p)
				el.clear();
		FOR(i, N)
		{
			FOR(j, N)
			{
				if (big[i][j] == small[0][0] && i <= N-M && j <= N-M)
				{
					if (M == 1)
						count += 1;
					else
						bq[i][j+1].push_back(1);
				}

				print("\nCell (%d, %d): ", i, j);
				for(auto &el : bq[i][j])
				{
					print("\n  > %d: ", el);
					int r_index, c_index;

					r_index = el / M;
					c_index = el % M;
					print("%c vs %c", big[i][j], small[r_index][c_index]);

					if (big[i][j] == small[r_index][c_index])
					{
						print(" OK, ");
						if (el+1 == M*M)
						{
							print("finished.");
							count += 1;
							continue;
						}

						if ((el+1) % M == 0)
						{
							print("added next row at (%d, %d)", i+1, j-c_index);
							bq[i+1][j-c_index].push_back(el+1);
						}
						else
						{
							print("added at (%d, %d)", i, j+1);
							bq[i][j+1].push_back(el+1);
						}
					}
				}
			}
		}

		printf("%d ", count);
		supp = small;
		for(int i=0; i < M; i++)
			for(int j=0; j < M; j++)
				supp[i][j] = small[M-j-1][i];
		small = supp;
		
		count = 0;
		for(auto &p : bq)
			for(auto &el : p)
				el.clear();
		FOR(i, N)
		{
			FOR(j, N)
			{
				if (big[i][j] == small[0][0] && i <= N-M && j <= N-M)
				{
					if (M == 1)
						count += 1;
					else
						bq[i][j+1].push_back(1);
				}

				print("\nCell (%d, %d): ", i, j);
				for(auto &el : bq[i][j])
				{
					print("\n  > %d: ", el);
					int r_index, c_index;

					r_index = el / M;
					c_index = el % M;
					print("%c vs %c", big[i][j], small[r_index][c_index]);

					if (big[i][j] == small[r_index][c_index])
					{
						print(" OK, ");
						if (el+1 == M*M)
						{
							print("finished.");
							count += 1;
							continue;
						}

						if ((el+1) % M == 0)
						{
							print("added next row at (%d, %d)", i+1, j-c_index);
							bq[i+1][j-c_index].push_back(el+1);
						}
						else
						{
							print("added at (%d, %d)", i, j+1);
							bq[i][j+1].push_back(el+1);
						}
					}
				}
			}
		}
		printf("%d\n", count);
	}

	return EXIT_SUCCESS;
}

void print(const char* msg, ...)
{
	#ifndef ONLINE_JUDGE
		va_list argptr;
		va_start(argptr, msg);
		vfprintf(stderr, msg, argptr);
		va_end(argptr);
	#endif
}