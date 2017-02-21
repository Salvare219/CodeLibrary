#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int p[100500];
int main()
{
    int n,d,a,b;
    while(~scanf("%d%d%d%d",&n,&d,&a,&b))
    {
        for(int i=0;i<n;i++)
            scanf("%d",p+i);
        int ia=0,ib=0,buy,now=0;
        for(int i=1;i<n;i++)
            if(p[i]>p[i-1])
            {
                ib=0;
                ia++;
                buy=min(ia*a,d/p[i]);
                d-=buy*p[i];
                now+=buy;
            }
            else if(p[i]<p[i-1])
            {
                ia=0;
                ib++;
                buy=min(ib*b,now);
                now-=buy;
                d+=p[i]*buy;
            }
            else
            {
                ia=ib=0;
            }
        printf("%d %d\n",d,now);
    }
    return 0;
}
