#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int t,h,y;
}a[2050],b[2050];
int n,x,k1,k2;
int cal(int s)
{
    int xx=x,cnt=0;
    for(int i=0;i<n;i++)b[i]=a[i];
    for(int i=0;i<n;i++)
    {
        int f=-1;
        for(int j=0;j<n;j++)
            if(b[j].t==s)
            {
                if(b[j].h<=xx)
                {
                    if(f==-1)f=j;
                    else
                    {
                        if(b[j].y>b[f].y)f=j;
                    }
                }
            }
        if(f==-1)return cnt;
        cnt++;s^=1;
        xx+=b[f].y;
        b[f].t=-1;
    }
    return cnt;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
    {
        int t,h,m;
        scanf("%d%d%d",&t,&h,&m);
        a[i].t=t;
        a[i].h=h;
        a[i].y=m;
    }
    int ans1=0,ans2=0;
    ans1=cal(0);
    ans2=cal(1);
    printf("%d\n",max(ans1,ans2));
    return 0;
}
