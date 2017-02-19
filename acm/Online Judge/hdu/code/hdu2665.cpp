#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int tree[20][100005],left[20][100005];
int num[100005];
bool cmp(int a,int b)
{
    return tree[1][a]<tree[1][b];
}
void build_tree(int l,int r,int dep)
{
    if(l==r)return;
    int mid=(l+r)>>1;
    int lpos=l,rpos=mid+1;
    for(int i=l;i<=r;i++)
    {
        if(tree[dep][i]>mid) tree[dep+1][rpos++]=tree[dep][i];
        else tree[dep+1][lpos++]=tree[dep][i];
        left[dep][i]=lpos-l;
    }
    build_tree(l,mid,dep+1);
    build_tree(mid+1,r,dep+1);
}
int query(int lef,int rig,int l,int r,int dep,int k)
{
    if(l==r) return tree[dep][l];
    int mid=(lef+rig)>>1;
    int cnt=left[dep][r]-((l!=lef)?left[dep][l-1]:0);
    if(cnt<k)
    {
        int newl=left[dep][rig]+l-((l!=lef)?left[dep][l-1]:0);
        int newr=newl+(r-l-cnt);
        return query(mid+1,rig,newl,newr,dep+1,k-cnt);
    }
    else
    {
        int newl=lef+((l!=lef)?left[dep][l-1]:0);
        int newr=newl+cnt-1;
        return query(lef,mid,newl,newr,dep+1,k);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&tree[1][i]),num[i]=i;
        sort(num+1,num+n+1,cmp);
        for(int i=1;i<=n;i++)
            tree[0][num[i]]=i;
        for(int i=1;i<=n;i++)
            num[i]=tree[1][num[i]];
        build_tree(1,n,0);
        int l,r,k;
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",num[query(1,n,l,r,0,k)]);
        }

    }
    return 0;
}
