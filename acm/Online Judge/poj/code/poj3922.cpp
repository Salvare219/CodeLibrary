#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int a[1000000];
int main()
{
 //   freopen("1.txt","r",stdin);
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,k=0;
        scanf("%d%d",&n,&m);
        a[0]=1;
        bool flag=0;
        for(i=0;a[i]<=n;i++)
        {
            if(a[i]==n) flag=1;
            while(a[k]*m<a[i]) k++;
            a[i+1]=a[i]+a[k];
        }
        if(flag) printf("Case %d: lose\n",ti++);
        else
        {
            while(n!=a[i])
            {
                n%=a[i];
                i--;
            }
            printf("Case %d: %d\n",ti++,n);
        }
    }
    return 0;
}
