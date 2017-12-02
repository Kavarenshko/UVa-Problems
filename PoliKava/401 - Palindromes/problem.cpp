#include <iostream>
#include <string.h>

using namespace std;

char m1[] = {'A', '\0', '\0', '\0', '3', '\0', '\0', 'H', 'I', 'L', '\0', 'J', 'M', '\0', 'O', '\0', '\0', '\0', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5'};
char m2[] = {'0', '1', 'S', 'E', '\0', 'Z', '\0', '\0', '8', '\0'};
char s[20+1];

bool checkPalindrome()
{
	int l = strlen(s);

	if (l == 1)
		return true;

	for(int i=0; i < (l/2); i++)
	{
		if (s[i] != s[l-i-1])
			return false;
	}
	return true;
}

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool compareChars(char c1, char c2)
{
	if ((c1 == '0' || c1 == 'O') && (c2 == '0' || c2 == 'O'))
		return true;
	
	if (isDigit(c1))
	{
		if (!m2[c1-48])
			return false;
		if (c2 != m2[c1-48])
			return false;
	}
	else
	{
		if (!m1[c1-65])
			return false;
		if (c2 != m1[c1-65])
			return false;
	}

	return true;
}

bool checkMirrored()
{
	int l = strlen(s);

	if (l == 1)
	{
		if (isDigit(s[0]))
			return m2[(s[0]-48)];
		else
			return m1[(s[0])-65];
	}

	for(int i=0; i < (l/2); i++)
	{
		char a = s[i];
		char b = s[l-i-1];

		if (!compareChars(a,b))
			return false;
	}

	if (l % 2 != 0)
	{
		if (isDigit(s[l/2+1]))
			return m2[(s[l/2+1]-48)];
		else
			return m1[(s[l/2+1])-65];
	}
	return true;
}

int main()
{
	while(scanf("%s\n", s) != EOF)
	{
		bool pal = checkPalindrome();
		bool rev = checkMirrored();

		if (pal && rev)
			cout << s << " -- is a mirrored palindrome.\n\n";
		else if (pal && !rev)
			cout << s << " -- is a regular palindrome.\n\n";
		else if (!pal && rev)
			cout << s << " -- is a mirrored string.\n\n";
		else
			cout << s << " -- is not a palindrome.\n\n";
	}

	return EXIT_SUCCESS;
}