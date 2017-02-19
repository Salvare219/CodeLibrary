#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    if(k>=n*(n-1)/2) printf("no solution\n");
    else
    {
        int x=0,y=0;
        for(int  i=0;i<n;i++)
        {
            printf("%d %d\n",x,y);
            y+=5000;
        }
    }
    return 0;
}
