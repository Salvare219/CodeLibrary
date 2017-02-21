#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("final.in", "r", stdin);
    freopen("final.out", "w", stdout);

    int n, p, k, d;
    scanf("%d%d%d%d", &n, &p, &k, &d);
    int m = d*(d-1)/2;
    
    if (d==1)
    {
        int s = p/k;
        if (s*n<p)
            printf("Wrong information\n");
        else
        {
            int left = p;
            for (int i=1; i<=n; i++)
                if (left>s)
                {
                    printf("%d\n", s);
                    left-=s;
                }
                else
                {
                    printf("%d\n", left);
                    left = 0;
                }
        }
    }
    else if (m>p)
        printf("Wrong information\n");
    else
    {
        printf("%d\n", d-1+p-m);
        for (int i=d-2; i; i--)
            printf("%d\n", i);
        for (int i=1; i<=n-(d-1); i++)
            printf("0\n");
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
