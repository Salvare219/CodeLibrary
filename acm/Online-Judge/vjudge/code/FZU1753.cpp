#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


bool vis[100032];
int prim[10000],pk;
void cal()
{
    for(int i=2;i<100031;i++)
    {
        if(vis[i]==0) prim[pk++]=i;
        for(int j=0;j<pk && prim[j]*i<100031;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}
inline long long __pow(long long a,int b)
{
    long long c=1;
    while(b)
    {
        if(b&1) c*=a;
        b>>=1;
        a*=a;
    }
    return c;
}
inline int get(int x,int k)
{
    int sum=0;
    while(x)
    {
        sum+=x/k;
        x/=k;
    }
    return sum;
}
int aa[200],bb[200];
int main()
{
	int n;
	cal();
	while(scanf("%d",&n)==1)
    {
        int x,y,ma=99999999;
        for(int i=0;i<n;i++)
            scanf("%d%d",aa+i,bb+i),ma=min(ma,aa[i]);
        long long s=1;
        for(int i=0;prim[i]<=ma;i++)
        {
            x=9999999;
            for(int j=0;j<n;j++)
                x=min(x,get(aa[j],prim[i])-get(aa[j]-bb[j],prim[i])-get(bb[j],prim[i]));
            s*=__pow(prim[i],x);
        }
        printf("%I64d\n",s);
    }
	return 0;
}
