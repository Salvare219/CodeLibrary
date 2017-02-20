#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int x[200050];
double a[5];
int n;
bool ok(double mid)
{
    int j;
    double s=x[0];
    a[0]=s+mid;

    j=upper_bound(x,x+n,2*mid+s)-x;

    s=x[j];
    a[1]=s+mid;

    j=upper_bound(x+j,x+n,2*mid+s)-x;

    s=x[j];
    a[2]=s+mid;

    if((x[n-1]-a[2]+1e-7)<=mid)return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",x+i);sort(x,x+n);
    double l=0,r=1e9/2,mid;
    x[n]=1e9+500;
    while(r-l>1e-7)
    {
        mid=(l+r)/2;
        if(ok(mid))r=mid;
        else l=mid;
    }
    ok(r+1e-7);
    printf("%.6f\n",r);
    for(int i=0;i<3;i++)
        if(a[i]>1e9+50) printf("%.6f ",1e9);
        else printf("%.6f ",a[i]);putchar(10);
	return 0;
}
