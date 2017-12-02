#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1)
    {
        if (cin.eof())
            break;
        string current;
        getline(cin, current);
        if (current == "" || current == " " || current == "\n")
            break;
        printf("%s\n", current.c_str());
    }
    return EXIT_SUCCESS;
}