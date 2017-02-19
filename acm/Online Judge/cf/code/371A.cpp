#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[10000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    int t=n/k,ans=0;
    for(int i=0;i<k;i++)
    {
        int a1=0,a2=0;
        for(int j=0;j<t;j++)
        {
            if(a[i+j*k]==1)a1++;
            else a2++;
        }
        ans+=min(a1,a2);
    }
    printf("%d\n",ans);
    return 0;
}
