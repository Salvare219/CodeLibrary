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
    int n,k;scanf("%d%d",&n,&k);
    if(k>(n-1)/2)puts("-1");
    else
    {
        printf("%d\n",n*k);
        for(int i=0;i<n;i++)
            for(int j=1;j<=k;j++)
                printf("%d %d\n",i+1,(i+j)%n+1);
    }
    return 0;
}
