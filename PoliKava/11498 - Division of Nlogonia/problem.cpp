#include <iostream>

using namespace std;

struct point
{
	int x;
	int y;
};

int compare(struct point& center, struct point& p)
{
	/*
		0: divisa
		1: SO (south west)
		2: NO (north west)
		3: SE (south east)
		4: NE (north east)
	*/

	if ((center.x == p.x) || (center.y == p.y))
		return 0;

	if (p.x < center.x) // west
	{
		if (p.y < center.y) // south
			return 1;
		else
			return 2; // north
	}
	else // east
	{
		if (p.y < center.y) // south
			return 3;
		else
			return 4; // north
	}
}

int main()
{
	int t;

	while (cin >> t)
	{
		point center;

		if (t == 0)
			break;

		cin >> center.x >> center.y;

		for(int i=0; i < t; i++)
		{
			point current;
			cin >> current.x >> current.y;

			switch(compare(center, current))
			{
				case 0:
					cout << "divisa\n";
					break;
				case 1:
					cout << "SO\n";
					break;
				case 2:
					cout << "NO\n";
					break;
				case 3:
					cout << "SE\n";
					break;
				case 4:
					cout << "NE\n";
					break;
			}

		}
	}

	return EXIT_SUCCESS;
}