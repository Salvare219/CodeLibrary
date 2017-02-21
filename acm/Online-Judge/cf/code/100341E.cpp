#include <bits/stdc++.h>

using namespace std;

int calx(int y, int bits)
{
    int resu = 0;
    for (int i=0; i<20; i++)
    {
        if (y&1)
        {
            resu+=(1<<i);
        }
        else
        {
            resu+=((bits&1)<<i);
            bits>>=1;
        }
        y>>=1;
    }
    return resu;
}

int main()
{
    //printf("%d\n", calx(2, 5));
    freopen("crypto.in", "r", stdin);
    freopen("crypto.out", "w", stdout);

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ansval = 0, ansx = 1, ansy = 1;

    for (int x = 1; x<=n; x++)
    {
        for(int y=(x-1)&x;y;y=(y-1)&x)
        {
            if (((a*x+b*y)^(a*y+b*x))>ansval)
            {
                ansval = ((a*x + b*y) ^ (a*y + b*x));
                ansx = x;
                ansy = y;
            }
        }
    }

    printf("%d %d\n", ansx, ansy);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
