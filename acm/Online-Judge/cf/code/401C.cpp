#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void pri(int n,int m)
{
    int y=m-n;
    for(int i=0;i<y;i++)
        printf("110");
    for(int i=y;i<n;i++)
        printf("10");
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    if(2*n<m)
    {
        if(m-2<=2*n)
        {
            pri(n,2*n);
            int c=m-2*n;
            if(c==1)printf("1");
            else printf("11");
        }
        else printf("-1");
    }
    else if(n>m)
    {
        if(n-1==m)
        {
            for(int i=0;i<m;i++)
                printf("01");printf("0");
        }
        else printf("-1");
    }
    else pri(n,m);
    putchar(10);
    return 0;
}
