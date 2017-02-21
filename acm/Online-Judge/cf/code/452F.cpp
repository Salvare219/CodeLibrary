#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const int seed=9901;
long long hash[300050];
struct bit_tree
{
    long long  bit[300050],s;
    inline void update(int x,long long  v)
    {
        while(x<300005)bit[x]+=v,x+=x&-x;
    }
    inline long long query(int x)
    {
        s=0;
        while(x)s+=bit[x],x-=x&-x;
        return s;
    }
}b,g;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    for(int i=hash[0]=1;i<300005;i++)
        hash[i]=hash[i-1]*seed;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        b.update(x,hash[x]);
        g.update(n-x+1,hash[n-x+1]);
        if(n>=2*x-1)
        {
            long long g1=b.query(x-1)*hash[n-2*x+1];
            long long g2=g.query(n-x)-g.query(n-2*x+1);
            if(g1!=g2)
                return puts("YES");
        }
        else
        {
            unsigned long long g1=b.query(n)-b.query(x);
            unsigned long long g2=(g.query(2*n-2*x+1)-g.query(n-x+1))*hash[2*x-n-1];
            if(g1!=g2)
                return puts("YES");
        }
    }
    return puts("NO");
}
