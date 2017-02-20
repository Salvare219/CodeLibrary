#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const int maxn = 100010;
struct Splaytree
{
	int sz[maxn];
	int ch[maxn][2];
	int pre[maxn];
	int rt,top;

	int cnt[maxn];
	int val[maxn];
	int dat[maxn];
	int lim;
	inline void push_up(int x)
	{
		sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
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
		if(pre[x])ch[pre[x]][ch[pre[y]][1]==y]=x;
		ch[x][f]=y;
		pre[y]=x;
		push_up(y);
	}
	inline void Splay(int x,int to)  //把编号为x的节点旋到编号为to的节点的下面
	{
		while(pre[x]!=to)            //可以改单旋试试
            Rotate(x,ch[pre[x]][0]==x);
		push_up(x);
		if(to==0)rt=x;
	}
    inline int get_kth(int k)  //得到第k大的节点编号 包含-INF,INF两个点
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
    inline int get_val(int v)  //得到值为v的节点编号 如果没有返回值小于v的第一个节点编号
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
	inline void Newnode(int &x,int c,int f,int w,int d)   //新建节点
	{
		pre[x=++top]=f;
		ch[x][0]=ch[x][1]=0;
		sz[x]=cnt[x]=w;
		val[x]=c;
		dat[x]=d;
	}
    ////////////////////////////////////
    inline void init()
    {
        ch[0][0]=ch[0][1]=pre[0]=0;
        sz[0]=cnt[0]=0;
        rt=top=0;
        Newnode(rt,-0x3fffffff,0,1,0);
        Newnode(ch[rt][1],0x3fffffff,rt,1,0);
        push_up(rt);
    }
    void insert(int x,int y)
    {
        Splay(get_val(y),0);
        Splay(get_nxt(),rt);
        int f=ch[rt][1];
        Newnode(ch[f][0],y,f,1,x);
        push_up(f);
        push_up(rt);
    }
    int pop(int f)
    {
        if(sz[rt]==2)return 0;
        else
        {
            int k;
            if(f)k=2;
            else k=sz[rt]-1;
            Splay(get_kth(k),0);
            k=dat[rt];
            Del_rt();
            return k;
        }
    }
}spt;
int main()
{
    int x,y,z;
    spt.init();
    while(scanf("%d",&x)&&x)
    {
        if(x==1)
        {
            scanf("%d%d",&y,&z);
            spt.insert(y,z);
        }
        else
            printf("%d\n",spt.pop(x-2));
    }
    return 0;
}



