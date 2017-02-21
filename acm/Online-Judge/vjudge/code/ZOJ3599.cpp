#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



long long a[29111];
int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,k=0;
        scanf("%d%d",&m,&n);
        a[0]=1;
        for(i=0;a[i]<=n;i++)
        {
            while(a[k]*m<a[i]) k++;
            a[i+1]=a[i]+a[k];
        }
        printf("%d\n",n-i);
    }
    return 0;
}
