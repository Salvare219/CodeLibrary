#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[100005];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k,x,f=0,ma=0x3fffffff;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&x),a[i%k]+=x;
    for(int i=0;i<k;i++)
        if(a[i]<ma) ma=a[i],f=i;
    printf("%d\n",f+1);
    return 0;
}

