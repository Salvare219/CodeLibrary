#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


const int maxn = 10010;
namespace LCT
{
	int ch[maxn][2];
	int pre[maxn];
	bool rt[maxn];

	int val[maxn];
	int dat[maxn];
	inline void push_up(int x)
	{
		dat[x]=max(val[x],max(dat[ch[x][0]],dat[ch[x][1]]));
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
	inline void Splay(int x)
	{
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
    int Access(int x)
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
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            ch[i][0]=ch[i][1]=0,rt[i]=1;
    }
    void updat(int x,int y)
    {
        Access(x);
        Splay(x);
        val[x]=y;
        push_up(x);
    }
    int query(int x,int y)
    {
        Access(x);
        int z=Access(y);
        //printf("%d %d %d\n",x,y,z);
        Splay(x);
        Splay(z);
        if(x==z)return dat[ch[z][1]];
        else return max(dat[x],dat[ch[z][1]]);
    }
}
vector<int>gra[10050],id[10050];
int how[10050],pos[10050];
void dfs(int s,int p)
{
    int y;
    LCT::pre[s]=p;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            pos[id[s][i]]=y;
            LCT::val[y]=LCT::dat[y]=how[id[s][i]];
            dfs(y,s);
        }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,y,z;scanf("%d",&n);
        LCT::init(n);
        for(int i=1;i<=n;i++)
            gra[i].clear(),id[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            gra[x].push_back(y);
            gra[y].push_back(x);
            id[x].push_back(i);
            id[y].push_back(i);
            how[i]=z;
        }
        dfs(1,0);
        char s[55];
        while(scanf("%s",s)&&s[0]!='D')
        {
            scanf("%d%d",&x,&y);
            if(s[0]=='Q')
                printf("%d\n",LCT::query(x,y));
            else
                LCT::updat(pos[x],y);
        }
    }
    return 0;
}