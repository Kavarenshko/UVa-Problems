#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 1000000000;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

void print(const char* msg, ...);

int R,C;
vector< vector<char> > v;
set<ii> used;

inline bool isValid(int r, int c) { return (r >= 1 && c >= 1 && r <= R && c <= C); }

void walk(int r, int c, char col)
{
	if (used.find({r,c}) != used.end())
		return;
	used.insert({r,c});

	int ar[] = {-1,0,1,0};
	int ac[] = {0,-1,0,1};

	for(int i=0; i < 4; i++)
	{
		if (isValid(r+ar[i],c+ac[i]) && v[r][c] == v[r+ar[i]][c+ac[i]])
			walk(r+ar[i],c+ac[i],col);
	}
	v[r][c] = col;
}

int main()
{
	while(1)
	{
		char command = getchar();
		print("%c\n", command);

		bool quit = false;
		switch(command)
		{
			case 'X':
			{
				quit = true;
				break;
			}
			case 'I':
			{
				scanf("%d %d", &C, &R);
				v.assign(R+1, vector<char>());
				for(auto &vv : v)
					vv.assign(C+1, 'O');

				break;
			}
			case 'C':
			{
				for(int i=1; i <= R; i++)
				{
					for(int j=1; j <= C; j++)
					{
						v[i][j] = 'O';
					}
				}

				break;
			}
			case 'L':
			{
				int r,c;
				char colour;
				scanf("%d %d %c", &c, &r, &colour);
				v[r][c] = colour;

				break;
			}
			case 'V':
			{
				int c,r1,r2;
				char colour;
				scanf("%d %d %d %c", &c,&r1,&r2,&colour);

				if (r1 > r2)
				{
					int mem = r1;
					r1 = r2;
					r2 = mem;
				}
				for(int i=r1; i <= r2; i++)
					v[i][c] = colour;

				break;
			}
			case 'H':
			{
				int c1,c2,r;
				char colour;
				scanf("%d %d %d %c", &c1, &c2, &r, &colour);

				if (c1 > c2)
				{
					int mem = c1;
					c1 = c2;
					c2 = mem;
				}

				for(int i=c1; i <= c2; i++)
					v[r][i] = colour;

				break;
			}
			case 'S':
			{
				string filename;
				cin >> filename;
				printf("%s\n", filename.c_str());
				for(int i=1; i <= R; i++)
				{
					for(int j=1; j <= C; j++)
					{
						printf("%c", v[i][j]);
					}
					printf("\n");
				}

				break;
			}
			case 'K':
			{
				int r1,r2,c1,c2;
				char colour;
				scanf("%d %d %d %d %c", &c1, &r1, &c2, &r2, &colour);
				for(int i=r1; i <= r2; i++)
				{
					for(int j=c1; j <= c2; j++)
					{
						v[i][j] = colour;
					}
				}

				break;
			}
			case 'F':
			{
				int r,c;
				char colour;
				scanf("%d %d %c", &c, &r, &colour);

				used.clear();
				walk(r,c,colour);

				break;
			}
			default:
			{
				break;
			}
		}
		string skipstring;
		getline(cin, skipstring);

		if (quit)
			break;
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