#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;


const int mod=7777777;
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
                return val[i]+=t;
        st[sz]=s;val[sz]=t;
        next[sz]=head[f];head[f]=sz++;
        return t;
    }
}sf,dp[2];
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
map<int,int>mp;
int sp[200];
int cal(int a[180][180],int m,int hh)
{
    for(int i=0;i<180;i++)
        for(int j=0;j<180;j++)
            a[i][j]=0;
    int f=0,lim=1<<(m<<1);
    sf.init();mp.clear();
    int cnt=0;
    sf.insert(0,hh);mp[hh]=++cnt;
    for(int i=0;i<sf.sz;i++)
    {
        dp[0].init();
        dp[0].insert(1,sf.st[i]);
        int f=0,how=0;
        for(int j=0;j<m;j++)
        {
            dp[f^=1].init();
            int s,h,l=j<<1,v;
            int x=3<<l,y=12<<l;
            for(int z=0;z<dp[f^1].sz;z++)
            {
                s=dp[f^1].st[z];v=dp[f^1].val[z];
                h=(x&s)^((y&s)>>2);h|=h<<2;
                if(!(x&s|y&s))dp[f].insert(v,s&~(9<<l)|(9<<l));
                else if(!(h>>l&3))dp[f].insert(v,cg(s,l,(x&s)>>l));
                else if((h>>l&3)<3)dp[f].insert(v,s^h),dp[f].insert(v,s);
                else if(((x&s)>>l)==2)dp[f].insert(v,s&~(15<<l));
                else if((s&~(15<<l))==0&&j==m-1)how+=v;
            }
        }
        int x=mp[sf.st[i]],y;
        sp[x-1]=how;
        for(int j=0;j<dp[f].sz;j++)
            if((y=dp[f].st[j])<lim)
            {
                y<<=2;
                if(mp.count(y)==0)
                    mp[y]=++cnt;
                a[mp[y]-1][x-1]+=dp[f].val[j];
                sf.insert(0,y);
            }
    }
    for(int i=0;i<cnt;i++)
        a[cnt][i]=sp[i];
    return cnt+1;
}
int c[180][180];
void mul(int a[180][180],int b[180][180],int n)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j])
                for(int k=0;k<n;k++)
                    c[i][k]=(c[i][k]+(long long)a[i][j]*b[j][k])%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=c[i][j];
}
void pow_mat(int a[180][180],int n,int b)
{
    int ii[180][180];
    for(int i=0;i<n;i++)
    {
        ii[i][i]=1;
        for(int j=i+1;j<n;j++)
            ii[i][j]=ii[j][i]=0;
    }
    while(b)
    {
        if(b&1)mul(ii,a,n);
        b>>=1;
        mul(a,a,n);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=ii[i][j];
}
int a[180][180];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        swap(n,m);
        int ans=0,x,y,f=4|2<<(m<<1);
        int sz=cal(a,m,f);
        pow_mat(a,sz,n);
        if(a[sz-1][0])printf("%d\n",a[sz-1][0]);
        else puts("Impossible");
    }
    return 0;
}
