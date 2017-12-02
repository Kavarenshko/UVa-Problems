#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; i++)
#define FOR1(i, n) for(int i=1; i <= n; i++)

using namespace std;

constexpr int INF = 0x7fffffff;
constexpr int MAX = 10001;

typedef long long ll;            // 19 digits
typedef unsigned long long llu;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vii> weighted_graph;

void print(const char* msg, ...);

int N;
double L,W;

struct sprinkler
{
	ll pos;
	ll radius;
	double start;
	double end;
};
struct sprinkler v[MAX];

bool custom(struct sprinkler const& l, struct sprinkler const& r)
{
    if (l.start < r.start)
    	return true;
    else if (l.start == r.start)
    {
    	if (l.end < r.end)
    		return true;
    }
    return false;
}

int main()
{
	FOR1(tc, INF)
	{
		if (scanf("%d %lf %lf", &N, &L, &W) != 3)
			break;

		print("\n\n- - - - - - - NEW TEST CASE - - - - - - - %d %lf %lf \n\n", N, L, W);

		FOR(i, N)
		{
			struct sprinkler curr;
			scanf("%lld %lld", &curr.pos, &curr.radius);

			if (curr.radius * 2 < W)
			{
				curr.start = curr.pos;
				curr.end = curr.pos;
			}
			else
			{
				double coeff = curr.pos * curr.pos + (W/2) * (W/2) - curr.radius * curr.radius;
				double delta = (-2 * curr.pos) * (-2 * curr.pos) - 4 * coeff;
				curr.start = (((-(-2 * curr.pos)) - sqrt(delta)) / 2);
				curr.end = (((-(-2 * curr.pos)) + sqrt(delta)) / 2);

				if (curr.start < 0.0)
					curr.start = 0.0;
				if (curr.end > L)
					curr.end = L;
			}
			v[i] = curr;
			print("\n\nPos: %d, radius: %d.\nCurrent start: %lf\nCurrent end: %lf", curr.pos, curr.radius, curr.start, curr.end);
		}

		sort(v, v + N, &custom);

		int tot = 0;
		int cindex = 0;
		double cend = -1.0;

		while(cindex < N)
		{
			if (v[cindex].start > 0)
				break;
			cend = v[cindex].end;
			cindex += 1;
		}
		tot += 1;

		print("\n(#%d) Current end: %lf", tc, cend);
		//continue;
		if (cend == -1.0)
		{
			printf("-1\n");
			continue;
		}
		else if (cend >= L)
		{
			printf("1\n");
			continue;
		}

		if (N == 1 && cend < L)
		{
			printf("-1\n");
			continue;
		}

		bool next = false;
		bool found = false;
		double curcend = 0.0;
		while(1)
		{
			if (cend >= L || curcend >= L)
			{
				tot += 1;
				break;
			}
			if (cindex >= N && cend < L)
			{
				next = true;
				break;
			}

			print("\nCurrent end: %lf, circle start : %lf, tot = %d", cend, v[cindex].start, tot);


			if (v[cindex].start > cend)
			{
				if (!found) // impossible, next test case
				{
					next = true;
					break;
				}
				else
				{
					if (cend == curcend)
					{
						next = true;
						break;
					}
					cend = curcend;
					tot += 1;
				}
			}
			else
			{
				curcend = max(curcend, v[cindex].end);
				print("\nCurcend is now equal to %lf", curcend);
				found = true;
				cindex += 1;
			}
		}

		if (next)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", tot);

		/*FOR(i, N)
		{
			print("\nSprinkler #%d: pos = %d, start = %lf, end = %lf", i, v[i].pos, v[i].start, v[i].end);
		}*/
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