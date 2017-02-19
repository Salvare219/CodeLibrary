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
    int n,x,y,sum=0;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++)
        scanf("%d",&y),sum+=y;
    if(sum==0)puts("0");
    else
    {
        sum=abs(sum);
        printf("%d\n",(sum+x-1)/x);
    }
    return 0;
}
