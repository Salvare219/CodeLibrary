#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int q[300050][3];
int ans[300060];
struct p
{
    int l,r;
    int dat,laz;
}tree[1400050];
void creat_tree(int i,int l,int r)
{
    tree[i].laz=0;
    tree[i].l=l;tree[i].r=r;
    if(l==r) ;
    else
    {
        creat_tree(2*i+1,l,(l+r)/2);
        creat_tree(2*i+2,(l+r)/2+1,r);
    }
}
void push_down(int i)
{
    tree[2*i+1].laz=tree[i].laz;
    tree[2*i+1].dat=tree[i].laz;
    tree[2*i+2].laz=tree[i].laz;
    tree[2*i+2].dat=tree[i].laz;
    tree[i].laz=0;
}
int query(int i,int l)
{
    if(tree[i].l==l && tree[i].r==l) return tree[i].dat;
    else
    {
        int mid=(tree[i].l+tree[i].r)/2;
        if(tree[i].laz) push_down(i);
        if(l>mid) return query(2*i+2,l);
        else if(l<=mid) return query(2*i+1,l);
    }
}
void updat(int i,int l,int r,int x)
{
    if(tree[i].l==l && tree[i].r==r) tree[i].laz=x,tree[i].dat=x;
    else
    {
        if(tree[i].laz) push_down(i);
        int mid=(tree[i].l+tree[i].r)/2;
        if(l>mid) updat(2*i+2,l,r,x);
        else if(r<=mid) updat(2*i+1,l,r,x);
        else updat(2*i+1,l,mid,x),updat(2*i+2,mid+1,r,x);
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    creat_tree(0,0,n-1);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
    memset(ans,-1,sizeof(ans));
    for(int i=m-1;i>-1;i--)
    {
        if(ans[q[i][2]-1]==-1) ans[q[i][2]-1]=query(0,q[i][2]-1);
        updat(0,q[i][0]-1,q[i][1]-1,q[i][2]);
    }
    for(int i=0;i<n;i++)
        if(ans[i]==-1) ans[i]=query(0,i);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
