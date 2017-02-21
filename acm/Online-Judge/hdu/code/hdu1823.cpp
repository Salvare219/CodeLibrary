#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct seg_tree
{
    int dat[4005];
    void creat_tree(int i,int l,int r)
    {
        dat[i]=-1;
        if(l<r)creat_tree(i<<1,l,l+r>>1),creat_tree(i<<1|1,(l+r>>1)+1,r);
    }
    inline void push_up(int i)
    {
        dat[i]=max(dat[i<<1],dat[i<<1|1]);
    }
    inline int query(int i,int l,int r,int l1,int r1)
    {
        if(l==l1&&r==r1)return dat[i];
        else
        {
            int mid=l+r>>1;
            if(l1>mid)return query(i<<1|1,mid+1,r,l1,r1);
            else if(r1<=mid)return query(i<<1,l,mid,l1,r1);
            else return max(query(i<<1,l,mid,l1,mid),query(i<<1|1,mid+1,r,mid+1,r1));
        }
    }
    inline void updat(int i,int l,int r,int l1,int x)
    {
        if(l==l1&&r==l1)dat[i]=max(dat[i],x);
        else
        {
            int mid=l+r>>1;
            if(l1>mid)updat(i<<1|1,mid+1,r,l1,x);
            else updat(i<<1,l,mid,l1,x);
            push_up(i);
        }
    }
};
struct index_tree
{
    int n,m,_l,_r,_x;
    struct seg_tree t[405];
    inline void _c(int i,int l,int r)
    {
        t[i].creat_tree(1,0,m);
        if(l<r)_c(i<<1,l,l+r>>1),_c(i<<1|1,(l+r>>1)+1,r);
    }
    inline int _q(int i,int l,int r,int l1,int r1)
    {
        if(l==l1 && r==r1) return t[i].query(1,0,m,_l,_r);
        else
        {
            int mid=l+r>>1;
            if(l1>mid)return _q(i<<1|1,mid+1,r,l1,r1);
            else if(r1<=mid) return _q(i<<1,l,mid,l1,r1);
            else return max(_q(i<<1,l,mid,l1,mid),_q(i<<1|1,mid+1,r,mid+1,r1));
        }
    }
    inline void _up(int i,int l,int r,int l1)
    {
        if(l==l1 && r==l1)t[i].updat(1,0,m,_l,_x);
        else
        {
            int mid=l+r>>1;t[i].updat(1,0,m,_l,_x);
            if(l1>mid)_up(i<<1|1,mid+1,r,l1);
            else _up(i<<1,l,mid,l1);
        }
    }
    ///>//////////////////////////////////
    void init(int l,int r)
    {
        n=l;m=r;
        _c(1,0,n);
    }
    inline void updat(int l,int r,int x)
    {
        _l=r;_x=x;
        _up(1,0,n,l);
    }
    inline int query(int l,int r,int l1,int r1)
    {
        _l=l1;_r=r1;
        return _q(1,0,n,l,r);
    }
}ind;
int main()
{
    int t;
    while(scanf("%d",&t)&&t)
    {
        char s[4];
        int h,a,l,h2;
        double te,te2;
        ind.init(100,1000);
        while(t--)
        {
            scanf("%s",s);
            if(s[0]=='I')
            {
                scanf("%d%lf%lf",&h,&te,&te2);
                a=te*10+1e-5;l=te2*10+1e-5;
                ind.updat(h-100,a,l);
            }
            else
            {
                scanf("%d%d%lf%lf",&h,&h2,&te,&te2);
                a=10*te+1e-5;l=10*te2+1e-5;
                if(h>h2)swap(h,h2);
                if(a>l)swap(a,l);
                h=ind.query(h-100,h2-100,a,l);
                if(h==-1)puts("-1");
                else printf("%d.%d\n",h/10,h%10);
            }
        }
    }
    return 0;
}
