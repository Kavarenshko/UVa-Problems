#include <iostream>

using namespace std;

struct pointXYZ
{
	int x;
	int y;
	int z;
};

int main()
{
	int l;
	pointXYZ ys[4] = {{1,0,0}, {0,1,0}, {-1,0,0}, {0,-1,0}};
	pointXYZ zs[4] = {{1,0,0}, {0,0,1}, {-1,0,0}, {0,0,-1}};

	while(1) // for every test case
	{
		cin >> l;

		if (l == 0)
			break;

		pointXYZ p = {1,0,0}; // +x, starting position
		int index = 0;
		char direction = 'x';

		for(int i=0; i < (l-1); i++)
		{
			string current;
			fflush(stdin);
			cin >> current;

			if (current == "No")
				continue;

			if (p.x) // on x axis, changes will be made
			{
				//cout << "Block x ";
				if (current[1] == 'y')
				{
					if (current[0] == '-')
					{
						index = (3+p.x-1)%4;
						p = ys[index];
					}
					else
					{
						index = (3+p.x+1)%4;
						p = ys[index];
					}
					direction = 'y';
				}
				else if (current[1] == 'z')
				{
					if (current[0] == '-')
					{
						index = (3+p.x-1)%4;
						p = zs[index];
					}
					else
					{
						index = (3+p.x+1)%4;
						p = zs[index];
					}
					direction = 'z';
				}
			}
			else if (direction == 'y' && current[1] == 'y')
			{
				//cout << "Block y ";
				if (current[0] == '-')
				{
					index = (3+index)%4;
					p = ys[index];
				}
				else
				{
					index = (3+index+2)%4;
					p = ys[index];
				}
			}
			else if (direction == 'z' && current[1] == 'z')
			{
				//cout << "Block z ";
				if (current[0] == '-')
				{
					index = (3+index)%4;
					p = zs[index];
				}
				else
				{
					index = (3+index+2)%4;
					p = zs[index];
				}
			}
			//cout << "\nCurrent P: (" << p.x << "," << p.y << "," << p.z << "). (" << i << ")\n";
		}

		if (p.x != 0)
		{
			cout << (p.x<0? '-':'+') << "x\n";
		}
		if (p.y != 0)
		{
			cout << (p.y<0? '-':'+') << "y\n";
		}
		if (p.z != 0)
		{
			cout << (p.z<0? '-':'+') << "z\n";
		}
	}

	return EXIT_SUCCESS;
}