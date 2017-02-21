#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int x,y,ti=1;
    while(scanf("%d%d",&x,&y)==2)
    {
        printf("Case #%d:\n",ti++);
        int a,b,t;
        for(int i=1;i<=x;i++,putchar(10))
            for(int j=1;j<=y;j++)
            {
                a=i,b=j;t=0;
                if(a>b)swap(a,b);
                while(a)
                {
                    if(b/a>1) break;
                    b%=a;swap(a,b);t^=1;
                }
                putchar(t?'P':'H');
            }
    }
    return 0;
}