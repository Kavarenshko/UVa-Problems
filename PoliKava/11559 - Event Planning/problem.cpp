#include <iostream>

#define MAX_INT 0x7ffffff

using namespace std;

int main()
{
	while(1)
	{
		int p,b,h,w,min_price=MAX_INT;

		if (!(cin >> p >> b >> h >> w))
			break;

		for(int i=0; i < h; i++)
		{
			int temp_price;
			cin >> temp_price;
			for(int j=0; j < w; j++)
			{
				int temp_beds;
				cin >> temp_beds;
				if (temp_beds < p) // there are not enough beds in this hotel/weekend
					continue;
				min_price = min(min_price, temp_price*p);
			}
		}

		if (min_price <= b)
			cout << min_price << "\n";
		else
			cout << "stay home\n";
	}

	return EXIT_SUCCESS;
}