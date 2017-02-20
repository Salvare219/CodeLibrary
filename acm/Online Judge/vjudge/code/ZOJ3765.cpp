#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


const int maxn = 300050;
int gcd(int x,int y)
{
    while(x&&y)x>y?x%=y:y%=x;
    return x+y;
}
struct Splaytree
{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int rt,top;

	int cnt[maxn];
	//int val[maxn];

	int dat[maxn];
	int sta[maxn];
	int g[maxn][2];

	inline void push_up(int x)
	{
		sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
		if(sta[x])
        {
            g[x][0]=gcd(g[ch[x][0]][0],g[ch[x][1]][0]);
            g[x][1]=gcd(dat[x],gcd(g[ch[x][0]][1],g[ch[x][1]][1]));
        }
        else
        {
            g[x][0]=gcd(dat[x],gcd(g[ch[x][0]][0],g[ch[x][1]][0]));
            g[x][1]=gcd(g[ch[x][0]][1],g[ch[x][1]][1]);
        }
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
	inline void Splay(int x,int to)  //把编号为x的节点旋到编号为to的节点的下面
	{
		while(pre[x]!=to)
            Rotate(x,ch[pre[x]][1]!=x);
		push_up(x);
		if(to==0)rt=x;
	}
    inline int get_kth(int k)  //得到第k大的节点编号
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
    inline int get_nxt()   //找到大于根的第一个节点编号
    {
        int x=ch[rt][1];
        push_down(x);
        while(ch[x][0])x=ch[x][0],push_down(x);
        return x;
    }
    inline int get_pre()   //找到小于根的第一个节点编号
    {
        int x=ch[rt][0];
        push_down(x);
        while(ch[x][1])x=ch[x][1],push_down(x);
        return x;
    }
	inline void Newnode(int &x,int f,int w,int da,int st)
	{
		pre[x=++top]=f;
		ch[x][0]=ch[x][1]=0;
		sz[x]=cnt[x]=w;
		//val[x]=c;
		dat[x]=da;
		sta[x]=st;
		g[x][st]=da;
		g[x][st^1]=0;
	}
	inline void Del_rt()    //删除根节点
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

    ////////////////////////////////////
    int num[200050],stat[200050];


    inline void init(int n)
    {
        ch[0][0]=ch[0][1]=pre[0]=0;
        sz[0]=cnt[0]=0;
        rt=top=0;
        Newnode(rt,0,1,0,0);
        Newnode(ch[rt][1],rt,1,0,0);

        build_tree(ch[ch[rt][1]][0],0,n-1,ch[rt][1]); //初始化num

        push_up(ch[rt][1]);
        push_up(rt);
    }
    inline void build_tree(int &x,int l,int r,int f)
    {
        if(l>r) return ;
        int mid=(l+r)>>1;
        Newnode(x,f,1,num[mid],stat[mid]);
        build_tree(ch[x][0],l,mid-1,x);
        build_tree(ch[x][1],mid+1,r,x);
        push_up(x);
        //printf("%d : %d %d %d\n",mid,dat[x],g[x][0],g[x][1]);
    }

    inline int query(int a,int b,int c)
    {
        Splay(get_kth(a),0);
        Splay(get_kth(b+2),rt);
        return g[ch[ch[rt][1]][0]][c];
    }

    inline void insert(int a,int b,int c)
    {
        Splay(get_kth(a+1),0);
        Splay(get_kth(a+2),rt);
        a=ch[rt][1];
        Newnode(ch[a][0],a,1,b,c);
        push_up(a);
        push_up(rt);
    }

    inline void del(int a)
    {
        Splay(get_kth(a+1),0);
        Del_rt();
    }

    inline void change(int a)
    {
        Splay(get_kth(a+1),0);
        sta[rt]^=1;
        push_up(rt);
    }

    inline void modi(int a,int b)
    {
        Splay(get_kth(a+1),0);
        dat[rt]=b;
        push_up(rt);
    }

}spt;

int main()
{
    int n,q;
    char s[44];
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&spt.num[i],&spt.stat[i]);
        spt.init(n);
        int a,b,c,d,e;
        while(q--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d%d",&a,&b,&c);
                int ans=spt.query(a,b,c);
                if(ans==0)ans=-1;
                printf("%d\n",ans);
            }
            else if(s[0]=='I')
            {
                scanf("%d%d%d",&a,&b,&c);
                spt.insert(a,b,c);
            }
            else if(s[0]=='D')
            {
                scanf("%d",&a);
                spt.del(a);
            }
            else if(s[0]=='R')
            {
                scanf("%d",&a);
                spt.change(a);
            }
            else
            {
                scanf("%d%d",&a,&b);
                spt.modi(a,b);
            }
        }
    }
    return 0;
}
