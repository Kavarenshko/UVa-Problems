#include <bits/stdc++.h>

using namespace std;

int main()
{
	string first_quote = "``";
	string second_quote = "''";
	bool state = false;
	bool started = false;

	while (!cin.eof())
	{

		if (started)
			printf("\n");
		else
			started = true;
		
		string curr_line, new_line = "";
		getline(cin, curr_line);

		for(int i=0; i < curr_line.size(); i++)
		{
			if (curr_line[i] == '"')
			{
				if (state)
				{
					state = false;
					new_line += second_quote;
				}
				else
				{
					state = true;
					new_line += first_quote;
				}
			}
			else
				new_line += curr_line[i];
		}
		printf("%s", new_line.c_str());
	}

	return EXIT_SUCCESS;
}