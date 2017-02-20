#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct point
{int x,y;}po[305];
long long a[305][305];
int mod=10007;
int pow_mod(int a,int b)
{
    int c=1;
    a%=mod;
    while(b)
    {
        if(b&1) c=(c*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return c;
}
int det(int n)
{
    int i,j,k,pa,pb;
    long long ans=1,pt;
    for(i=0;i<n;i++)
    {
        k=i;
        for(j=i;j<n;j++)
            if(a[j][i])
            {
                k=j;
                break;
            }
        if(a[k][i]==0) return -1;
        if(k!=i)for(ans=mod-ans,j=i;j<n;j++) swap(a[i][j],a[k][j]);
        for(j=i+1;j<n;j++)
            if(a[j][i])
            {
                if(a[i][i]>a[j][i])pa=i,pb=j;
                else pa=j,pb=i;
                while(a[pb][i])
                {
                    swap(pa,pb);
                    pt=a[pb][i]/a[pa][i];
                    for(k=i;k<n;k++)
                        a[pb][k]=(a[pb][k]-a[pa][k]*pt)%mod;
                }
                if(i!=pa)for(ans=mod-ans,k=i;k<n;k++)swap(a[i][k],a[j][k]);
            }
        ans=(ans*a[i][i])%mod;
    }
    return (ans+mod)%mod;
}
inline int dis(int i,int j)
{
    return ((po[i].x-po[j].x)*(po[i].x-po[j].x)+(po[i].y-po[j].y)*(po[i].y-po[j].y));
}
inline bool in(int i,int j,int k)
{
    int dx1=po[i].x-po[k].x,dx2=po[j].x-po[k].x;
    int dy1=po[i].y-po[k].y,dy2=po[j].y-po[k].y;
    if(dx1*dy2==dy1*dx2)
    {
        if(po[i].x==po[j].x)
        {
            if(dy1*dy2>=0) return 0;
            else return 1;
        }
        else
        {
            if(dx1*dx2>=0) return 0;
            else return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,r;
        scanf("%d%d",&n,&r);
        r*=r;
        for(int i=0;i<n;i++)
            scanf("%d%d",&po[i].x,&po[i].y);
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
                if(dis(i,j)<=r)
                {
                    bool fl=1;
                    for(int k=0;k<n;k++)
                        if(in(i,j,k)) fl=0;
                    if(fl==0) continue;
                    a[i][i]++;a[j][j]++;
                    a[i][j]=a[j][i]=-1;
                }
        }
        printf("%d\n",det(n-1));
    }
    return 0;
}


