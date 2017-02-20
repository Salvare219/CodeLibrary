#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long s[100005],h[100005],dp1[100005],dp2[100005],pre[100005];
int q[100005];
inline bool xv(int i,int j,long long ss)
{
    return (dp1[j]+pre[j]-dp1[i]-pre[i])<=ss*(j-i);
}
inline long long xmult(int i,int j,int k)
{
    return (j-i)*(dp1[k]+pre[k]-dp1[i]-pre[i])-(dp1[j]+pre[j]-dp1[i]-pre[i])*(k-i);
}
int main()
{
    int n,m,p,x;scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<n;i++)
        scanf("%d",&x),s[i+1]=s[i]+x;
    for(int i=1;i<=m;i++)
        scanf("%d%I64d",&x,h+i),h[i]-=s[x];
    sort(h+1,h+m+1);
    for(int i=1;i<=m;i++)pre[i]=pre[i-1]+h[i],dp1[i]=h[i]*i-pre[i];
    for(int i=1;i<p;i++)
    {
        int f=0,t=0;
        for(int j=i+1;j<=m;j++)
        {
            while(f+1<t&&xmult(q[t-2],q[t-1],j-1)<0)t--;
            q[t++]=j-1;
            while(f+1<t&&xv(q[f],q[f+1],h[j]))f++;
            x=q[f];
            dp2[j]=dp1[x]+h[j]*(j-x)-(pre[j]-pre[x]);
        }
        for(int j=i+1;j<=m;j++)
            dp1[j]=dp2[j];
    }
    printf("%I64d\n",dp1[m]);
    return 0;
}
