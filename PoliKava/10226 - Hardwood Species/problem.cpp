#include <iostream>
#include <map>
#include <set>
#include <cstring>

using namespace std;

map<string, int> m;
set<string> s; // keep the trees in alphabetical order

int main()
{
	int tc, nTrees;

	cin >> tc;
	cin.ignore();

	for(int i=0; i < tc; i++)
	{
		nTrees = 0;
		m.erase(m.begin(), m.end());
		s.erase(s.begin(), s.end());

		if (i)
			printf("\n"); // blank line between consecutive test cases
		else
			cin.get();

		while(1)
		{
			string current = "";

			if (cin.eof())
				break;

			getline(cin, current);

			if (current == "")
			{
				//printf("BLANK LINE\n");
				break;
			}

			nTrees++;

			if (m.find(current) == m.end())
			{
				m[current] = 1;
				s.insert(current);
				//printf("New to map: %s.\n", current.c_str());
			}
			else
			{
				//printf("String %s already in map.\n", current.c_str());
				m[current] += 1;
			}
			//printf("%s\n", current.s);
			//printf("\nSet length: %d", s.size());
		}

		for(auto it = s.begin(); it != s.end(); it++)
		{
			printf("%s %.4lf\n", (*it).c_str(), (double)m[(*it).c_str()]*100/nTrees);
			//printf("%s %.4lf\n", *it, nTrees / (double)m[*it]);
		}
	}

	return EXIT_SUCCESS;
}