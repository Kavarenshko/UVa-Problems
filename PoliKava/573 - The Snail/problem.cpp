#include <iostream>

using namespace std;

int main()
{
	int h,u,d,f; // h = height, u = distance traveled during the day, d = sliding distance, f = fatigue percentage

	while (cin >> h >> u >> d >> f, h) // if h == 0 break
	{
		// for every test case
		int day=0;
		double distance = 0.0;
		double fatigue_factor = (u*f)/100.0;

		while(++day)
		{
			double climbing_distance = u - fatigue_factor*(day-1);

			if (climbing_distance < 0)
				climbing_distance = 0;

			distance += climbing_distance;

			if (distance > h)
			{
				cout << "success on day " << day << "\n";
				break;
			}
			else if ((distance < 0.0) || ((distance - d) < 0))
			{
				cout << "failure on day " << day << "\n";
				break;
			}
			distance -= d;
		}
	}

	return 0;
}