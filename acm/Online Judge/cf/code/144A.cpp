#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[200];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,ma=-1,mi=0x3fffffff;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),ma=max(ma,a[i]),mi=min(mi,a[i]);
    int x,y;
    for(x=0;a[x]!=ma;x++);
    for(y=n-1;a[y]!=mi;y--);
    if(x<y) printf("%d\n",x+n-1-y);
    else printf("%d\n",x+n-1-y-1);
    return 0;
}


