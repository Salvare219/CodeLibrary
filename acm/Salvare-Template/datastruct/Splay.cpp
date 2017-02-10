const int maxn = 100010;
struct Splaytree
{
    int sz[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int rt,top;

    int cnt[maxn];
    int val[maxn];
    bool laz[maxn];
    inline void push_up(int x)
    {
        sz[x]=cnt[x]+sz[ch[x][0]]+sz[ch[x][1]];
    }
    inline void push_down(int x)
    {
        if(laz[x])
        {
            swap(ch[x][0],ch[x][1]);
            if(ch[x][0])laz[ch[x][0]]^=1;
            if(ch[x][1])laz[ch[x][1]]^=1;
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
        if(pre[x])ch[pre[x]][ch[pre[y]][1]==y]=x;
        ch[x][f]=y;
        pre[y]=x;
        push_up(y);
    }
    inline void Splay(int x,int to)  //把编号为 x 的节点旋到编号为 to 的节点的下面
    {
        while(pre[x]!=to)            //可以改单旋试试
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
    inline int get_kth(int k)  //得到第 k 大的节点编号 包含 -INF , INF 两个点
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
    inline int get_val(int v)  //得到值为 v 的节点编号 如果没有返回值小于 v 的第一个节点编号
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
    inline void Newnode(int &x,int c,int f,int w)   //新建节点 &x=ch[f][?] c 为权值 f 为父亲 w 为大小(一般是 1 )
    {
        pre[x=++top]=f;
        ch[x][0]=ch[x][1]=0;
        sz[x]=cnt[x]=w;
        val[x]=c;
    }
    ////////////////////////////////////

    inline void init()
    {
        ch[0][0]=ch[0][1]=pre[0]=0;
        sz[0]=cnt[0]=0;
        rt=top=0;
        Newnode(rt,-0x3fffffff,0,1);
        Newnode(ch[rt][1],0x3fffffff,rt,1);

        //build_tree(ch[ch[rt][1]][0],0,n-1,ch[rt][1]); //初始化 num

        push_up(ch[rt][1]);
        push_up(rt);
    }
    void build_tree(int &x,int l,int r,int f)
    {
        if(l>r) return ;
        int mid=(l+r)>>1;
        Newnode(x,num[mid],f,1);
        build_tree(ch[x][0],l,mid-1,x);
        build_tree(ch[x][1],mid+1,r,x);
        push_up(x);
    }

}spt;