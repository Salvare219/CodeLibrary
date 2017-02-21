#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


long long h[100050],p[100050];
int n,m;
bool ok(long long t)
{
    if(t==101)
        int kk=0;
    int fin=0;
    long long s,now;
    for(int i=0;i<n;i++)
    {
        s=t;
        if(fin==m) return 1;
        if(h[i]-p[fin]>t) return 0;
        if(p[fin]<h[i])
        {
            s-=2*(h[i]-p[fin]);
            if(s<0) now=h[i];
            else now=h[i]+s;
            now=max(now,h[i]+(t-h[i]+p[fin])/2);
        }
        else now=h[i]+t;
        while(fin<m && p[fin]<=now) fin++;
    }
    if(fin==m) return 1;
    fin=m-1;
    for(int i=n-1;i>-1;i--)
    {
        s=t;
        if(fin==-1) return 1;
        if(p[fin]-h[i]>t) return 0;
        if(p[fin]>h[i])
        {
            s-=2*(p[fin]-h[i]);
            if(s<0) now=h[i];
            else now=h[i]-s;
            now=min(now,h[i]-(t+h[i]-p[fin])/2);
        }
        else now=h[i]-t;
        while(fin>-1 && p[fin]>=now) fin--;
    }
    if(fin==-1) return 1;
    else return 0;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%I64d",h+i);
    for(int i=0;i<m;i++)
        scanf("%I64d",p+i);
    long long l=0,r=1000000,mid;
    r*=r;
    while(l<r)
    {
        mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    printf("%I64d\n",r);
    return 0;
}


