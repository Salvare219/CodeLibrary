#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

inline int Int()
{
	int a=0;char c=getc(stdin),s;
	while(c<'0')s=c,c=getc(stdin);
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getc(stdin);
	return s!='-'?a:-a;
}
struct zkw_tree
{
    int num[100005],m,dep;
    long long laz[400050],dat[400050];
    inline void push_up(int i)
    {
        dat[i]=dat[i<<1]+dat[i<<1|1];
    }
    inline void push_down(int i,int len)
    {
        laz[i<<1]+=laz[i];
        dat[i<<1]+=laz[i]*len;
        laz[i<<1|1]+=laz[i];
        dat[i<<1|1]+=laz[i]*len;
        laz[i]=0;
    }
    void creat_tree(int n)
    {
        dep=0;m=1;n+=2;
        while(m<n)m<<=1,dep++;n-=2;
        for(int i=1;i<=n;i++)dat[i|m]=num[i-1],laz[i|m]=0;
        for(int i=n+1;i<m;i++)dat[i|m]=0,laz[i|m]=0;
        for(int i=m-1;i>0;i--)push_up(i);
    }
    inline long long query(int l,int r)
    {
        long long ans=0;l=m|l-1;r=m|r+1;
        for(int i=dep;i>0;i--)
        {
            if(laz[l>>i])push_down(l>>i,1<<i-1);
            if(laz[r>>i])push_down(r>>i,1<<i-1);
        }
        while((l^r)>1)
        {
            if(!(l&1))ans+=dat[l|1];
            if(r&1)ans+=dat[r^1];
            r>>=1;l>>=1;
        }
        return ans;
    }
    inline void updat(int l,int r,long long x)
    {
        int len=m;l=m|l-1;r=m|r+1;
        for(int i=dep;i>0;i--)
        {
            len>>=1;
            if(laz[l>>i])push_down(l>>i,len);
            if(laz[r>>i])push_down(r>>i,len);
        }
        while((l^r)>1)
        {
            if(!(l&1))laz[l|1]+=x,dat[l|1]+=x*len;
            if(r&1)laz[r^1]+=x,dat[r^1]+=x*len;
            push_up(r>>=1);push_up(l>>=1);len<<=1;
        }
        while(l>1)push_up(l>>=1);
    }
}t;
int main()
{
    int n=Int(),q=Int();
    for(int i=0;i<n;i++)t.num[i]=Int();
    t.creat_tree(n);
    char s=0;
    int x,y,z=1;
    while(q--)
    {
        while((s=getchar())<'A');
        if(s=='C')
            x=Int(),y=Int(),z=Int(),t.updat(x,y,z);
        else
            x=Int(),y=Int(),printf("%lld\n",t.query(x,y));
    }
    return 0;
}
