#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n, x = 2000000000, y = -2000000000;
    scanf("%d", &n);
    int f = 1;
    int z = 0;
    int dis = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        dis += a;
        if (b == 1)
        {
            x = min (z, x);
        }
        else
        {
            f = 0;
            y = max (z, y);
        }
        z += a;
    }
    if (f == 1)
        puts ("Infinity");
    else
    {
        if (x > y)
            printf ("%d\n", z + (1899 - y));
        else
            puts ("Impossible");
    }
	return 0;
}
