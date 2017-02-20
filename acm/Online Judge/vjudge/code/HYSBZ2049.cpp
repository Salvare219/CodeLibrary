#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;



const int maxn = 10050;
int ch[maxn][2];
int pre[maxn];
bool rt[maxn];

bool rev[maxn];
inline void push_up(int x)
{

}
inline void push_down(int x)
{
    if(rev[x])
    {
        int l=ch[x][0],r=ch[x][1];
        swap(ch[l][0],ch[l][1]);
        swap(ch[r][0],ch[r][1]);
        rev[l]^=1;rev[r]^=1;
        rev[x]=0;
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
        Rotate(x,ch[pre[x]][0]==x);
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
    Access(x);Splay(x);rev[x]^=1;
    swap(ch[x][0],ch[x][1]);
}
inline int Find_root(int x)
{
    Access(x);Splay(x);
    while(ch[x][0])x=ch[x][0];
    return x;
}
inline void Link(int x,int y)
{
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
        ch[i][0]=ch[i][1]=pre[i]=rev[i]=0,rt[i]=1;
}
inline bool query(int x,int y)
{
    while(pre[x])x=pre[x];
    while(pre[y])y=pre[y];
    return x==y;
}
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    init(n);
    char s[20];
    int x,y;
    while(m--)
    {
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='C')
            Link(x,y);
        else if(s[0]=='D')
            Cut(x,y);
        else
            puts(query(x,y)?"Yes":"No");
    }
    return 0;
}
