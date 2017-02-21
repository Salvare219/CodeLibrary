#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    if(k>=m)puts("1.00000000");
    else
    {
        if(k+n<m)puts("0.000000000");
        else
        {
            double ans=1.0;
            int lim=max(n+k+1,m);
            for(int i=1;i<=lim;i++)
            {
                if(i<=n)ans*=i;
                if(i<=n+k+1)ans/=i;
                if(i<=m)ans*=i;
                if(i<=m-k-1)ans/=i;
            }
            printf("%.9f\n",1.0-ans);
        }
    }
    return 0;
}
