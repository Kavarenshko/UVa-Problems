#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline bool isUpperCase(char c) { return c <= 'Z'; } // avoid checking for 'A' because it is assumed that c is a letter

string getUpperCase(string s)
{
	string t = "";
	for(int i=0; i < s.length(); i++)
	{
		if (isUpperCase(s[i]))
			t += s[i];
		else
			t += (s[i] - 32); // 97 - 65
	}
	return t;
}

int main()
{
	int i;
	char c;
	bool blank = true; // false can read

	vector<string> v;
	vector<string> u; // upercase version
	vector<string> solution;
	string temp = "";

	while(scanf("%c", &c) != EOF) // should not be necessary since the file is terminated by '#'
	{
		if (c == '#')
			break;

		if (c == ' ' || c == '\n') // check separators
		{
			if (!blank) // was I reading a word?
			{
				v.push_back(temp);
				u.push_back(getUpperCase(temp));
				temp = "";
			}

			blank = true;
			continue;
		}

		// c now is a letter for sure
		blank = false;
		temp += c;
	}

	i = 0;

	for(auto it = u.begin(); it < u.end(); it++, i++)
	{
		bool isAnAnagram = true;
		string current = *it;
		int clen = current.length();

		if (clen == 1) // yes
		{
			solution.push_back(v[i]);
			continue;
		}

		sort(current.begin(), current.end());
		for(auto jt = u.begin(); jt < u.end(); jt++)
		{
			if (it == jt) // pointer comparison 
				continue; // ^ that was an useless comment

			string other = *jt;

			if (clen != other.length())
				continue;

			sort(other.begin(), other.end());
			if (current == other)
			{
				isAnAnagram = false;
				//cout << "Word " << current << "\n";
				break;
			}
		}

		if (isAnAnagram)
			solution.push_back(v[i]);
	}

	sort(solution.begin(), solution.end());
	for(auto it = solution.begin(); it < solution.end(); it++)
	{
		printf("%s\n", (*it).c_str());
	}

	return EXIT_SUCCESS;
}