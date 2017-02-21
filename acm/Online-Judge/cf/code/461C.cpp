#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int bit[100060];
int a[100050];
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
void updat(int x,int v)
{
    while(x<100005)bit[x]+=v,x+=x&-x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,q;scanf("%d%d",&n,&q);
    int f=0,l=1,r=n;
    for(int i=1;i<=n;i++)
        a[i]=1,updat(i,1);
    while(q--)
    {
        int ty,x,y,len;
        scanf("%d",&ty);
        len=r-l+1;
        if(ty==1)
        {
            scanf("%d",&x);
            int ff=2*x>len;
            if(ff)x=len-x;
            if(ff^f)
            {
                for(int i=0;i<x;i++)
                {
                    updat(r-i,-a[r-i]);
                    updat(r-x-x+i+1,a[r-i]);
                    a[r-x-x+i+1]+=a[r-i];
                    a[r-i]=0;
                }
                r-=x;
            }
            else
            {
                for(int i=0;i<x;i++)
                {
                    updat(l+i,-a[l+i]);
                    updat(l+x+x-i-1,a[l+i]);
                    a[l+x+x-i-1]+=a[l+i];
                    a[l+i]=0;
                }
                l+=x;
            }
            if(ff)f^=1;
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",f?(query(r-x)-query(r-y)):(query(l+y-1)-query(l+x-1)));
        }
    }
    return 0;
}
