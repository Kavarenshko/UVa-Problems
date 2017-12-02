#include <iostream>
#include <algorithm>
#include <cmath>

#define MAXN 3000 + 10

using namespace std;

int main()
{
    int n;
    bool j[MAXN],c;
    int s[MAXN];

    while(scanf("%d", &n) == 1)
    {
        fill(j, j+MAXN, false);
        fill(s, s+MAXN, 0x7fffffff);
        c = true;

        for(int i=0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            s[i] = temp;
        }
        
        if (n == 1)
        {
            cout << "Jolly\n";
            continue;
        }
        
        for(int i=0; i < (n-1); i++)
        {
              int curr = abs(s[i]-s[i+1]);
              if (!j[curr])
              {
                  j[curr] = true;
              }
        }

       for(int i=1; i < n; i++)
       {
           if(!j[i])
           {
               cout << "Not jolly\n";
               c = false;
               break;
           }
       }

        if (c)
            cout << "Jolly\n";
    }

    return EXIT_SUCCESS;
}