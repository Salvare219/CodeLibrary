#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,i,j,a,b;
    scanf("%d%d%d%d%d%d",&n,&m,&i,&j,&a,&b);
    int x[]={1,n,n,1},y[]={m,1,m,1};
    bool f=1;
    int ans=999999;
    for(int z=0;z<4;z++)
    {
        int d1=abs(i-x[z]),d2=abs(j-y[z]);
        if(d1==0&&d2==0)
        {
            ans=0;f=0;
            break;
        }
        if(d1%a==0&&d2%b==0)
        {
            d1/=a;d2/=b;
            if(d1%2==d2%2)
            {
                bool pp=0;
                if(i+a<=n&&i+a>=1&&j+b>=1&&j+b<=m)pp=1;
                if(i+a<=n&&i+a>=1&&j-b>=1&&j-b<=m)pp=1;
                if(i-a<=n&&i-a>=1&&j+b>=1&&j+b<=m)pp=1;
                if(i-a<=n&&i-a>=1&&j-b>=1&&j-b<=m)pp=1;
                if(pp)ans=min(ans,max(d1,d2)),f=0;
            }
        }
    }
    if(f) puts("Poor Inna and pony!");
    else printf("%d\n",ans);
    return 0;
}
