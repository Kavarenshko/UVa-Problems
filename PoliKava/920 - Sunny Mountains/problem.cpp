#include <bits/stdc++.h>

using namespace std;

constexpr int MAXPOINTS = 100;

struct point
{
	double x;
	double y;
};

bool isLower(const struct point& a, const struct point& b)
{
	return (a.x > b.x);
}

double getDistance(struct point& a, struct point& b)
{
	return fabs(sqrt(pow((double)(b.x - a.x), 2) + pow((double)(b.y - a.y), 2)));
}

int main()
{
	int t;
	struct point points[MAXPOINTS] = {};

	cin >> t;
	while(t--)
	{
		int n;
		double height_max = 0;
		double covered = 0;
		cin >> n;

		for (int i=0; i < n; i++)
			cin >> points[i].x >> points[i].y;

		sort(points, points+n, &isLower);

		for(int i=0; i < n; i++)
		{
			//printf("\nI (%.2lf,%.2lf), I+1 (%.2lf,%.2lf)", points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
			if (points[i+1].y > points[i].y && points[i+1].y >= height_max)
			{
				if (height_max == 0)
				{
					height_max = points[i+1].y;
					covered = getDistance(points[i], points[i+1]);
				}
				else
				{
					double m = (points[i].y-points[i+1].y)/(points[i].x-points[i+1].x);
					double intersection = (height_max - points[i+1].y + m*points[i+1].x) / m;

					//printf("\n    > M: %.2lf, P.x: %.2lf", m, intersection);

					struct point horizon;
					horizon.y = height_max;
					horizon.x = intersection;

					covered += getDistance(points[i+1], horizon);
					height_max = points[i+1].y;
				}
				//printf("\nCovered: %.2lf, height max: %.2lf", covered, height_max);
			}
		}
		printf("%.2lf\n", covered);

	}

	return EXIT_SUCCESS;
}