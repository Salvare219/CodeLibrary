#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const int sd=10007;
struct Hash_map
{
    int head[sd],st[sd],next[sd],sz;
    int val[sd];
    void init()
    {
        memset(head,0xff,sizeof(head));sz=0;
    }
    int insert(int t,int s)
    {
        int f=s%sd;
        for(int i=head[f];~i;i=next[i])
            if(st[i]==s)
                return val[i]=max(t,val[i]);
        st[sz]=s;val[sz]=t;
        next[sz]=head[f];head[f]=sz++;
        return t;
    }
}dp[2];
int cg(int s,int l,int f)
{
    int z=(f&1)?2:-2,cnt=0;
    s^=(f|f<<2)<<l;
    while(cnt>=0)
    {
        l+=z;
        if((s>>l&3^f)==3)cnt--;
        if((s>>l&3^f)==0)cnt++;
    }
    return s^3<<l;
}
int a[12][12];
int main()
{
    int n,m,ti=1;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int f=0,lim=1<<(m<<1);
        dp[0].init();
        dp[0].insert(0,1);
        int ans=-1000000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[f^=1].init();
                int s,h,l=j<<1;
                int x=3<<l,y=12<<l;
                int v;
                for(int z=0;z<dp[f^1].sz;z++)
                {
                    s=dp[f^1].st[z];v=dp[f^1].val[z];
                    h=(x&s)^((y&s)>>2);h|=h<<2;
                    if(!(x&s|y&s))dp[f].insert(v+a[i][j],s&~(9<<l)|(9<<l)),dp[f].insert(v,s);
                    else if(!(h>>l&3))dp[f].insert(v+a[i][j],cg(s,l,(x&s)>>l));
                    else if((h>>l&3)<3)
                    {
                        if(((x&s)>>l&3)==0)dp[f].insert(v+a[i][j],s^h),dp[f].insert(v+a[i][j],s);
                        else dp[f].insert(v+a[i][j],s^h),dp[f].insert(v+a[i][j],s);
                        if((s&~(5<<l))==0&&i==n-1&&j==m-1)ans=max(ans,v+a[i][j]);
                    }
                    else if(((x&s)>>l)==2)dp[f].insert(v+a[i][j],s&~(15<<l));
                }
            }
            dp[f^1].init();
            for(int j=0;j<dp[f].sz;j++)
                if(dp[f].st[j]<lim)dp[f^1].insert(dp[f].val[j],dp[f].st[j]<<2);
            f^=1;
        }
        printf("Case %d: %d\n",ti++,ans);
    }
    return 0;
}
