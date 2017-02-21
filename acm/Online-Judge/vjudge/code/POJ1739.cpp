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
    long long val[sd];
    void init()
    {
        memset(head,0xff,sizeof(head));sz=0;
    }
    int insert(long long t,int s)
    {
        int f=s%sd;
        for(int i=head[f];~i;i=next[i])
            if(st[i]==s)
                return val[i]+=t;
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
char a[12][12],b[12][12];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=0;i<n;i++)
            scanf("%s",b[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[j][i]=b[i][m-j-1];
        swap(n,m);
        if(a[n-1][m-1]=='#');
        else
        {
            int f=0,lim=1<<(m<<1);
            dp[0].init();
            dp[0].insert(1,lim<<1);
            long long ans=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    dp[f^=1].init();
                    int s,h,l=j<<1;
                    int x=3<<l,y=12<<l;
                    long long v;
                    for(int z=0;z<dp[f^1].sz;z++)
                    {
                        s=dp[f^1].st[z];v=dp[f^1].val[z];
                        h=(x&s)^((y&s)>>2);h|=h<<2;
                        if(a[i][j]=='#')!(x&s|y&s)?dp[f].insert(v,s):0;
                        else if(!(x&s|y&s))dp[f].insert(v,s&~(9<<l)|(9<<l));
                        else if(!(h>>l&3))dp[f].insert(v,cg(s,l,(x&s)>>l));
                        else if((h>>l&3)<3)
                        {
                            dp[f].insert(v,s^h),dp[f].insert(v,s);
                            if((s&~(15<<l))==0&&i==n-1&&j==m-1)ans+=v;
                        }
                        else if(((x&s)>>l)==2)dp[f].insert(v,s&~(15<<l));
                    }
                }
                dp[f^1].init();
                for(int j=0;j<dp[f].sz;j++)
                    if(dp[f].st[j]<lim)dp[f^1].insert(dp[f].val[j],dp[f].st[j]<<2);
                f^=1;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}