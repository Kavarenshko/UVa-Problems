#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	int h,m;

	while(1)
	{
		scanf("%d:%d", &h, &m);

		if (!h && !m)
			break;

		double min_angle, hrs_angle, r;

		min_angle = m * 6;
		hrs_angle = (h * 30) + (m / 2.0);
		r = min(fabs(hrs_angle - min_angle), fabs(min_angle - hrs_angle));

		if (r > 180)
		{
			r = 180 - (r - 180);
		}

		cout << fixed << setprecision(3) << r << "\n";
	}

	return EXIT_SUCCESS;
}