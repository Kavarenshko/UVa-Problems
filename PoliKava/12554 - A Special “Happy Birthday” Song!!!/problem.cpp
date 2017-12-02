#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 100;

int main()
{
	bool s[MAXN] = {false};
	int n, c, s_index = 0;
	string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	vector<string> names;

	scanf("%d", &n); getchar();
	c = n;

	for(int i=0; i < n; i++)
	{
		string a;
		getline(cin, a);
		names.push_back(a);
	}

	while(1)
	{
		if (c == 0 && s_index%16 == 0)
			break;

		printf("%s: %s\n", names[s_index%n].c_str(), song[s_index%16].c_str());
		if (s[s_index%n] == false)
		{
			s[s_index%n] = true;
			c -= 1;
		}
		s_index += 1;
	}

	return EXIT_SUCCESS;
}