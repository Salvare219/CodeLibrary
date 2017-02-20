#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 30050;
namespace LCT
{
    int ch[maxn][2];
    int pre[maxn];
    bool rt[maxn];

    int val[maxn];
    int dat1[maxn];
    int dat2[maxn];
    inline void push_up(int x)
    {
        dat1[x]=max(val[x],max(dat1[ch[x][0]],dat1[ch[x][1]]));
        dat2[x]=val[x]+dat2[ch[x][1]]+dat2[ch[x][0]];
    }
    inline void push_down(int x)
    {

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
        //P(x);
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
    inline void init(int n)
    {
        for(int i=1;i<=n;i++)
            ch[i][0]=ch[i][1]=pre[i]=0,rt[i]=1;
    }
    inline void updat(int x,int y)
    {
        Access(x);Splay(x);
        val[x]=y;
        push_up(x);
    }
    inline int query1(int x,int y)
    {
        Access(x);
        int z=Access(y);
        Splay(x);Splay(z);
        if(x==z)return max(val[x],dat1[ch[z][1]]);
        else return max(val[z],max(dat1[x],dat1[ch[z][1]]));
    }
    inline int query2(int x,int y)
    {
        Access(x);
        int z=Access(y);
        Splay(x);Splay(z);
        if(x==z)return val[x]+dat2[ch[z][1]];
        else return val[z]+dat2[x]+dat2[ch[z][1]];
    }
}
vector<int>gra[30050];
void dfs(int s,int p)
{
    int y;
    LCT::pre[s]=p;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
            dfs(y,s);
}
int main()
{
    int n,x,y;scanf("%d",&n);
    LCT::init(n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    LCT::dat1[0]=-1000000;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        LCT::val[i]=LCT::dat1[i]=LCT::dat2[i]=x;
    }
    dfs(1,0);
    int m;scanf("%d",&m);
    char s[20];
    while(m--)
    {
        scanf("%s%d%d",s,&x,&y);
        if(s[0]=='C')
            LCT::updat(x,y);
        else if(s[1]=='M')
            printf("%d\n",LCT::query1(x,y));
        else
            printf("%d\n",LCT::query2(x,y));
    }
    return 0;
}
