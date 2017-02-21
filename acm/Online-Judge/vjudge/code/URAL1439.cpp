#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

/*
struct p
{
    int x,y;
    bool operator<(const p&a)
    {
        return x<a.x;
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&po[i].x,&po[i].y);
    int k=0;
    for(int i=1;i<=n;i++)
        po[k].x=i,po[k++].y=m+1;
    for(int i=1;i<=m;i++)
        po[k].x=n+1,po[k++].y=;
    for(;;)
	return 0;
}

*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
const int maxn = 100010;

	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int rt,top;

	int cnt[maxn];
	int val[maxn];
	int lim;
	inline void push_up(int x)
	{
		sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
	}
    inline void push_down(int x)
    {
        ;
    }
	inline void Rotate(int x,int f)//f=1 right
	{
		int y=pre[x];
        push_down(y);
        push_down(x);
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
			if(pre[pre[x]]==to)Rotate(x,ch[pre[x]][0]==x);
			else
            {
				bool f=(ch[pre[pre[x]]][0]==pre[x]);
				if(ch[pre[x]][f]==x)Rotate(x,!f),Rotate(x,f);
				else Rotate(pre[x],f),Rotate(x,f);
			}
		push_up(x);
		if(to==0)rt=x;
	}
    inline int get_kth(int k)
    {
        int x=rt;
        push_down(x);
        while(x)
        {
            if(k<=sz[ch[x][0]])x=ch[x][0];
            else if(k>sz[ch[x][0]]+cnt[x])k-=sz[ch[x][0]]+cnt[x],x=ch[x][1];
            else return x;
            push_down(x);
        }
        return 0;
    }
    inline int get_val(int v)
    {
        int x=rt,y;
        push_down(x);
        while(x)
        {
            if(v<val[x])x=ch[x][0];
            else if(v>val[x])x=ch[y=x][1];
            else return x;
            push_down(x);
        }
        return y;
    }
    inline int get_nxt()
    {
        int x=ch[rt][1];
        push_down(x);
        while(ch[x][0])x=ch[x][0],push_down(x);
        return x;
    }
    inline int get_pre()
    {
        int x=ch[rt][0];
        push_down(x);
        while(ch[x][1])x=ch[x][1],push_down(x);
        return x;
    }
	inline void Newnode(int &x,int c,int f,int w)
	{
		pre[x=++top]=f;
		ch[x][0]=ch[x][1]=0;
		sz[x]=w;cnt[x]=w;
		val[x]=c;
	}
	inline void Del_rt()
	{
		int t=rt;
		if(ch[rt][1])
        {
			rt=ch[rt][1];
			Splay(get_kth(1),0);
			ch[rt][0]=ch[t][0];
			if(ch[rt][0])pre[ch[rt][0]]=rt;
		}
		else rt=ch[rt][0];
		pre[rt]=0;
		push_up(rt);
	}
    inline void init()
    {
        ch[0][0]=ch[0][1]=pre[0]=0;
        sz[0]=cnt[0]=0;
        rt=top=0;
        Newnode(rt,-0x3fffffff,0,1);
        Newnode(ch[rt][1],0x3fffffff,rt,1);
        pre[top]=rt;

        //build_tree(ch[ch[rt][1]][0],0,n-1,ch[rt][1]); //初始化num

        push_up(ch[rt][1]);
        push_up(rt);
    }

    ////////////////////////////////////

    void ini(int n)
    {
        init();
        Newnode(ch[ch[rt][1]][0],1,ch[rt][1],n);
        push_up(ch[rt][1]);push_up(rt);
    }
    void del(int x)
    {
        int t = get_kth(x);
        Splay(t,0);

        int pre = sz[ch[t][0]];
        int z=x-pre-1,zz=cnt[t]-z-1;
        int le = val[t];
        val[t] = val[t] + z + 1;
        cnt[t] = zz;
        push_up(t);
        int p=get_pre();
        Splay(p,0);
        Splay(t,rt);
        Newnode(ch[t][0],le,t,z);
        push_up(t);
        push_up(rt);
    }
    int query(int x)
    {
        Splay(get_kth(x),0);
        return val[rt]+x-sz[ch[rt][0]]-1;
    }
char S()
{
    char c=getchar();
    while(c<'A')c=getchar();
    return c;
}
char s;
int main()
{
    int n=Int(),m=Int(),x;
    ini(n);
    for(int i=0;i<m;i++)
    {
        s=S();
        x=Int();
        if(s=='D')
            del(x + 1);
        else
            printf("%d\n",query(x + 1));
    }
    return 0;
}
