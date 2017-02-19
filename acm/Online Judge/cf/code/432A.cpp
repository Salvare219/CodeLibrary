#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
   // freopen("1.txt","r",stdin);
    int n,k,x,sum=0;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(5-x>=k)sum++;
    }
    printf("%d\n",sum/3);
    return 0;
}

