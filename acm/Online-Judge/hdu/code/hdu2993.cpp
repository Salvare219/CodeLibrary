#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

inline int Int()
{
    int a=0;char c=getchar();
    while(c<'0')c=getchar();
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
    return a;
}
int sta[100005],y[100005];
inline bool xmult(int a,int b,int c)
{
    return (b-a)*(1ll*y[c]-y[a])-(1ll*y[b]-y[a])*(c-a)<=0;
}
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int f=0,t=0;
        double ans=0.0;
        for(int i=1;i<=n;i++)
            y[i]=y[i-1]+Int();
        for(int i=0;i<=n-k;i++)
        {
            while(f>t+1&&xmult(sta[f-2],sta[f-1],i))f--;
            sta[f++]=i;
            while(f>t+1&&!xmult(sta[t],sta[t+1],i+k))t++;
            ans=max(ans,1.0*(y[i+k]-y[sta[t]])/(i+k-sta[t]));
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
