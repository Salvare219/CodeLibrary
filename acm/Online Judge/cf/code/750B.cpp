#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n, x = 0, y = 0;
    scanf ("%d", &n);
    int f = 1;
    for(int i = 0; i < n; i++)
    {
        int a;
        char s[55];
        scanf("%d%s", &a, s);
        if (s[0] == 'S')
            x += a;
        if (s[0] == 'N')
            x -= a;
        if (s[0] == 'W')
        {
            if (x == 0 || x == 20000)
                f = 0;
            y += a;
        }
        if (s[0] == 'E')
        {
            if (x == 0 || x == 20000)
                f = 0;
            y -= a;
        }
        if (x < 0 || x > 20000)
            f = 0;
    }
    if (x == 0);
    else f = 0;
    puts (f? "YES" : "NO");
	return 0;
}
