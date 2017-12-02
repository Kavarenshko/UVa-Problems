#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_LEN = 1010;

vector<string> m(MAX_LEN);

int main()
{
    while(1)
    {
        string s;
        getline(cin, s);

        if (s == "" || s == "\n" || s == " ")
            break;

        if (s.size() == 1)
        {
            printf("%s\n", s.c_str());
            continue;
        }

        for(unsigned i=0; i < s.size(); i++)
            m[i] = s.substr(i,1);

        for(int i=s.size()-1; i >= 0; i--)
        {
            for(int j=s.size()-1; j > i; j--)
            {
                if (s[j] == s[i])
                {
                    string word;
                    if (j > i+1)
                        word = s[i] + m[j-1] + s[i];
                    else
                        word = m[i] + m[i];
                    for(unsigned k=j; k < s.size() && word.size() > m[k].size(); k++)
                        m[k] = word;
                }
            }
        }

        printf("%s\n", m[s.size()-1].c_str());
    }
    
    return EXIT_SUCCESS;
}