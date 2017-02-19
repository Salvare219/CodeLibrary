#include <bits/stdc++.h>

using namespace std;

int n,m;
//printf("((x%d|y%d)&(x%d&y%d))",a,a,b,b);
void pri(int a,int b)
{
    if(a>b)swap(a,b);
    putchar('(');
    if(n<m)
    {
        int f1=0,f2=0;
        if(a<=n)
            f1=2;
        else
            f1=0;
        if(b<=n)
            f2=2;
        else if(b<=m)
            f2=1;
        else
            f2=0;
        if(f1==2)
            printf("(x%d|y%d)",a,a);
        if(f1&&f2)
            putchar('&');
        if(f2==1)
            printf("y%d",b);
        else if(f2==2)
            printf("(x%d&y%d)",b,b);
    }
    else
    {
        int f1=0,f2=0;
        if(a<=m)
            f1=2;
        else
            f1=0;
        if(b<=m)
            f2=2;
        else if(b<=n)
            f2=1;
        else
            f2=0;
        if(f1==2)
            printf("(x%d|y%d)",a,a);
        if(f1&&f2)
            putchar('&');
        if(f2==1)
            printf("x%d",b);
        else if(f2==2)
            printf("(x%d&y%d)",b,b);
    }
    putchar(')');
}
int main()
{
    freopen("merge.in", "r", stdin);
    freopen("merge.out","w",stdout);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n+m;i++)
        {
            int has=0;
            for(int j=1;j<=n+1;j++)
            {
                int a=j,b=i-j+1;
                {
                    if(b>=1&&b<=m+1)
                    {
                        if(has)
                            putchar('|');
                        pri(a,b);
                        has=1;
                    }
                }
            }
            putchar(10);
        }
    }
    return 0;
}
