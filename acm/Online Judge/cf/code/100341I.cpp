#include<bits/stdc++.h>
using namespace std;

struct node{
    int x[4],p;
}a[100005];
int n,s;
int f[100005];

int dp[100005][30];
int to[100050];
inline void rmq()
{
    for(int i=0;i<n;i++)dp[i][0]=a[i].p;
    for(int l=2,s=0;l<=n;l<<=1,s++)
        for(int i=0;i+l<=n;i++)
            dp[i][s+1]=max(dp[i][s],dp[i+l/2][s]);
}
inline void pre_log()
{
    to[1]=0;
    for(int i=2;i<100005;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
const double C=log(2.0);
inline int query(int l,int r)
{
    if(l>r) swap(l,r);
    int mid=to[r-l+1];
    int len=1<<mid;
    return max(dp[l][mid],dp[r-len+1][mid]);
}

inline bool cmp1(const node& a,const node& b)
{
    return a.x[0]==b.x[0]?a.x[1]<b.x[1]:a.x[0]<b.x[0];
}
inline bool cmp2(const node& a,const node& b)
{
    return a.x[1]==b.x[1]?a.x[0]<b.x[0]:a.x[1]<b.x[1];
}
inline bool cmp3(const node& a,const node& b)
{
    return a.x[2]==b.x[2]?a.x[0]<b.x[0]:a.x[2]<b.x[2];
}
inline bool cmp4(const node& a,const node& b)
{
    return a.x[3]==b.x[3]?a.x[0]<b.x[0]:a.x[3]<b.x[3];
}

inline void J(int i,int j)
{
    if(i>=0&&f[i]>=0&&f[j]>=0)
    {
        int k=query(f[i],f[j]);
        if(k>i&&k>j)
            s=min(s,i);
    }
}
inline void G(int u)
{
    rmq();
    int i,j,P;
    for(j=i=0;i<n;i++)
    {
        if(a[i].x[u]!=a[j].x[u])
            for(;j<i;j++)
                f[a[j].p]=-1;
        f[P=a[i].p]=i;
        J(P,P+1);J(P-1,P);
    }
    for(;j<i;j++)
        f[a[j].p]=-1;
}

int main()
{
    freopen("queen2.in","r",stdin);
    freopen("queen2.out","w",stdout);
    int i;
    memset(f,-1,sizeof(f));
    for(scanf("%d",&n),i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x[0],&a[i].x[1]);
        a[i].x[2]=a[i].x[0]+a[i].x[1];
        a[i].x[3]=a[i].x[0]-a[i].x[1];
        a[i].p=i;
    }
    for(s=0;s<n;s++)
    {
        for(i=0;i<4;i++)
            if(a[s].x[i]==a[s+1].x[i])
                break;
        if(i>=4)
            break;
    }
    n++;
    pre_log();
    sort(a,a+n,cmp1);G(0);
    sort(a,a+n,cmp2);G(1);
    sort(a,a+n,cmp3);G(2);
    sort(a,a+n,cmp4);G(3);
    printf("%d\n",s);
    return 0;
}
