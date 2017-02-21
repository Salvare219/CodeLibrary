#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;



int num[200005];
int val[200005],laz[200005];
int siz[200005],ch[200005][2],pre[200005];
int root,top1;
inline void push_up(int x)
{
    siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
    val[x]=max(max(val[ch[x][0]],val[ch[x][1]]),laz[x]);
}
inline void push_down(int x)
{
    ;
}
void rotate(int x,int f)     //f=1 right
{
    int y=pre[x];
    push_down(y);
    push_down(x);
    ch[y][!f]=ch[x][f];
    pre[ch[x][f]]=y;
    pre[x]=pre[y];
    if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
    ch[x][f]=y;
    pre[y]=x;
    push_up(y);
}
void splay(int x,int to)
{
    push_down(x);
    while(pre[x]!=to)
        if(pre[pre[x]]==to)rotate(x,ch[pre[x]][0]==x);
        else
        {
            int f=(ch[pre[pre[x]]][0]==pre[x]);
            if(ch[pre[x]][f]==x)rotate(x,!f),rotate(x,f);
            else rotate(x,f),rotate(x,f);
        }
    push_up(x);
    if(to==0) root=x;
}
void rotate_to(int k,int to)
{
    int x=root;
    push_down(x);
    while(siz[ch[x][0]]!=k)
    {
        if(k<siz[ch[x][0]]) x=ch[x][0];
        else k-=siz[ch[x][0]]+1,x=ch[x][1];
        push_down(x);
    }
    splay(x,to);
}
void newnode(int &x,int c,int f)
{
    x=++top1;
    pre[x]=f;
    ch[x][0]=ch[x][1]=0;
    siz[x]=1;
    val[x]=laz[x]=c;
}
int query(int l,int r)
{
    rotate_to(l-1,0);
    rotate_to(r+1,root);
    return val[ch[ch[root][1]][0]];
}
void init()
{
    ch[0][0]=ch[0][1]=pre[0]=0;
    siz[0]=0;
    val[0]=laz[0]=0;
    root=top1=0;
    newnode(root,-0x3fffffff,0);
    newnode(ch[root][1],0x3fffffff,root);
    pre[top1]=root;siz[root]=2;
}
void insert(int k,int c)
{
    rotate_to(k,0);
    rotate_to(k+1,root);
    newnode(ch[ch[root][1]][0],c,ch[root][1]);
    push_up(ch[root][1]);
    push_up(root);
}
void updat(int l,int c)
{
    rotate_to(l-1,0);
    rotate_to(l+1,root);
    laz[ch[ch[root][1]][0]]=c;
    push_up(ch[ch[root][1]][0]);
}
int main()
{
    int n,m=__builtin_clz(42141);
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int x,y;
        for(int i=0;i<n;i++)
            scanf("%d",&x),insert(i,x);
        char s[5];
        for(int i=0;i<m;i++)
        {
            scanf("%s%d%d",s,&x,&y);
            if(s[0]=='Q')
                printf("%d\n",query(x,y));
            else
                updat(x,y);
        }
    }
    return 0;
}