#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int x[1000050],y[1000050];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,te;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&te),x[te]=i;
    for(int i=0;i<n;i++)
        scanf("%d",&te),y[x[te]]=i;
    for(int i=0;i<n;i++)x[i]=0;x[0]=0x3fffffff;
    int k=1,p;
    for(int i=0;i<n;i++)
    {
        p=upper_bound(x,x+k,y[i],cmp)-x;
        x[p]=max(x[p],y[i]);
        k=max(p+1,k);
    }
    printf("%d\n",k-1);
	return 0;
}
