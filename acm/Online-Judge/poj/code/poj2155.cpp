#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

inline int Int()
{
	int a=0;char c=getc(stdin),s;
	while(c<'0')s=c,c=getc(stdin);
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getc(stdin);
	return s!='-'?a:-a;
}
struct bit_tree
{
    bool bit[1005],s;
    inline void __updat(int x)
    {
        while(x<1004) bit[x]^=1,x+=x&-x;
    }
    inline void updat(int l,int r)
    {
        __updat(l);
        __updat(r+1);
    }
    inline bool query(int x)
    {
        s=0;
        while(x) s^=bit[x],x-=x&-x;
        return s;
    }
};
struct index_tree
{
    int sz,l1,r1;
    struct bit_tree t[4005];
    inline void creat_tree(int i,int l,int r)
    {
        memset(t[i].bit,0,sizeof(t[i].bit));
        if(l<r)creat_tree(i<<1,l,l+r>>1),creat_tree(i<<1|1,(l+r>>1)+1,r);
    }
    inline bool query(int i,int l,int r,int ll)
    {
        if(l==ll && r==ll) return t[i].query(l1);
        else
        {
            int mid=l+r>>1;
            if(ll>mid)return query(i<<1|1,mid+1,r,ll)^t[i].query(l1);
            else return query(i<<1,l,mid,ll)^t[i].query(l1);
        }
    }
    inline void updat(int i,int l,int r,int ll,int rr)
    {
        if(l==ll && r==rr)t[i].updat(l1,r1);
        else
        {
            int mid=l+r>>1;
            if(ll>mid)updat(i<<1|1,mid+1,r,ll,rr);
            else if(rr<=mid)updat(i<<1,l,mid,ll,rr);
            else updat(i<<1,l,mid,ll,mid),updat(i<<1|1,mid+1,r,mid+1,rr);
        }
    }
}ind;
int main()
{
    int t;scanf("%d",&t);
    bool f=0;
    while(t--)
    {
        if(f)putchar(10);f=1;
        int n=Int(),q=Int();
        ind.sz=n;
        ind.creat_tree(1,1,n);
        char s=0;
        int x,y,x1,y1;
        while(q--)
        {
            while((s=getchar())<'A');
            if(s=='C')
            {
                x=Int();y=Int();x1=Int();y1=Int();
                ind.l1=y;ind.r1=y1;
                ind.updat(1,1,n,x,x1);
            }
            else
            {
                x=Int();y=Int();
                ind.l1=y;
                printf("%d\n",ind.query(1,1,n,x));
            }
        }
    }
	return 0;
}
