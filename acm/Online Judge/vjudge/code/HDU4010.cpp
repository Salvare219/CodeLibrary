#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 300050;
int ch[maxn][2];
int pre[maxn];
bool rt[maxn];

bool rev[maxn];
long long laz[maxn];
long long val[maxn];
long long big[maxn];
inline void push_up(int x)
{
    big[x]=max(val[x],max(big[ch[x][0]],big[ch[x][1]]));
}
inline void Rev(int x)
{
    swap(ch[x][0],ch[x][1]);
    rev[x]^=1;
}
inline void add(int x,int v)
{
    laz[x]+=v;
    val[x]+=v;
    big[x]+=v;
}
inline void push_down(int x)
{
    if(rev[x])
    {
        Rev(ch[x][0]);Rev(ch[x][1]);
        rev[x]=0;
    }
    if(laz[x])
    {
        add(ch[x][0],laz[x]);add(ch[x][1],laz[x]);
        laz[x]=0;
    }
}
inline void Rotate(int x,int f)//f=1 right
{
    int y=pre[x];
    push_down(y);
    push_down(x);
    ch[y][!f]=ch[x][f];
    pre[ch[x][f]]=y;
    pre[x]=pre[y];
    if(rt[y])rt[x]=1,rt[y]=0;
    else ch[pre[x]][ch[pre[y]][1]==y]=x;
    pre[y]=x;
    ch[x][f]=y;
    push_up(y);
}
inline void P(int x)
{
    if(!rt[x])P(pre[x]);
    push_down(x);
}
inline void Splay(int x)
{
    P(x);
    while(!rt[x])
        if(rt[pre[x]])Rotate(x,ch[pre[x]][0]==x);
        else
        {
            bool f=(ch[pre[pre[x]]][0]==pre[x]);
            if(ch[pre[x]][f]==x)Rotate(x,!f),Rotate(x,f);
            else Rotate(pre[x],f),Rotate(x,f);
        }
    push_up(x);
}
inline int Access(int x)
{
    int y=0;
    for(;x;x=pre[y=x])
    {
        Splay(x);
        rt[ch[x][1]]=1;
        rt[ch[x][1]=y]=0;
        push_up(x);
    }
    return y;
}
inline void Make_root(int x)
{
    Access(x);Splay(x);
    Rev(x);
}
inline int Find_root(int x)
{
    while(pre[x])x=pre[x];
    return x;
}
inline void Link(int x,int y)
{
    if(Find_root(x)==Find_root(y))
    {
        printf("-1\n");
        return;
    }
    Make_root(x);
    pre[x]=y;
}
inline void Cut(int x,int y)
{
    Access(x);
    int z=Access(y);
    Access(z);
    Splay(z^=x^y);
    pre[z]=0;
}
inline void init(int n)
{
    for(int i=1;i<=n;i++)
        ch[i][0]=ch[i][1]=pre[i]=rev[i]=laz[i]=0,rt[i]=1;
}
inline void Dest(int x,int y)
{
    if(Find_root(x)!=Find_root(y)||x==y)
    {
        printf("-1\n");
        return;
    }
    Make_root(x);
    Access(y);
    Splay(y);
    pre[ch[y][0]]=pre[y];
    rt[ch[y][0]]=1;
    ch[y][0]=0;
    pre[y]=0;
    push_up(y);
}
inline void updat(int x,int y,int z)
{
    if(Find_root(x)!=Find_root(y))
    {
        printf("-1\n");
        return;
    }
    Make_root(x);
    Access(y);Splay(y);
    add(y,z);
}
inline long long query(int x,int y)
{
    if(Find_root(x)!=Find_root(y))return -1;
    Make_root(x);
    Access(y);Splay(y);
    return big[y];
}
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x,y,z;
        init(n);
        for(int i=1;i<n;i++)
            Link(Int(),Int());
        big[0]=val[0]=-(1ll<<60);
        for(int i=1;i<=n;i++)
            big[i]=val[i]=Int();
        int m=Int();
        while(m--)
        {
            x=Int();y=Int();z=Int();
            if(x==1)
                Link(y,z);
            else if(x==2)
                Dest(y,z);
            else if(x==3)
                x=Int(),updat(x,z,y);
            else
                printf("%I64d\n",query(y,z));
        }
        putchar(10);
    }
    return 0;
}