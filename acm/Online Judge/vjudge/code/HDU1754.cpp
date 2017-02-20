#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const int maxn = 200050;
namespace spt
{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int rt,top;

	int cnt[maxn];
	int val[maxn];
	int dat[maxn];
	inline void push_up(int x)
	{
		sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
        dat[x]=max(val[x],max(dat[ch[x][0]],dat[ch[x][1]]));
	}
	inline void Rotate(int x,int f)//f=1 right
	{
		int y=pre[x];
		ch[y][!f]=ch[x][f];
		pre[ch[x][f]]=y;
		pre[x]=pre[y];
		if(pre[x])ch[pre[x]][ch[pre[y]][1]==y]=x;
		ch[x][f]=y;
		pre[y]=x;
		push_up(y);
	}
	inline void Splay(int x,int to)
	{
		while(pre[x]!=to)
            Rotate(x,ch[pre[x]][0]==x);
		push_up(x);
		if(to==0)rt=x;
	}
    inline int get_kth(int k)
    {
        int x=rt;
        while(x)
        {
            if(k<=sz[ch[x][0]])x=ch[x][0];
            else if(k>sz[ch[x][0]]+cnt[x])k-=sz[ch[x][0]]+cnt[x],x=ch[x][1];
            else return x;
        }
        return 0;
    }
	inline void Newnode(int &x,int c,int f,int w)
	{
		pre[x=++top]=f;
		ch[x][0]=ch[x][1]=0;
		sz[x]=cnt[x]=w;
		val[x]=dat[x]=c;
	}
    int ans[200050],z;
    inline void init()
    {
        z=0;
        ch[0][0]=ch[0][1]=pre[0]=0;
        sz[0]=cnt[0]=0;
        rt=top=0;
        Newnode(rt,-0x3fffffff,0,1);
        Newnode(ch[rt][1],-0x3fffffff,rt,1);
        push_up(rt);
    }
    inline void insert(int x,int y)
    {
        Splay(get_kth(x),0);
        Splay(get_kth(x+1),rt);
        int f=ch[rt][1];
        Newnode(ch[f][0],y,f,1);
        push_up(f);
        push_up(rt);
    }
    inline int query(int x,int y)
    {
        Splay(get_kth(x),0);
        Splay(get_kth(y+2),rt);
        return dat[ch[ch[rt][1]][0]];
    }
    inline void updat(int x,int y)
    {
        Splay(get_kth(x+1),0);
        val[rt]=y;
        push_up(rt);
    }
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        spt::init();
        for(int i=1;i<=n;i++)
            scanf("%d",&x),spt::insert(i,x);
        for(int i=0;i<m;i++)
        {
            char s[4];
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='Q')
                printf("%d\n",spt::query(x,y));
            else
                spt::updat(x,y);
        }
    }
    return 0;
}



