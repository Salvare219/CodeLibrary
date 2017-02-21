#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int pos[10050];
int a[10050];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(pos,-1,sizeof(pos));
        int x,y,sum=0;pos[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum=(sum+a[i])%n;
            if(pos[sum]==-1)pos[sum]=i;
            else
            {
                x=pos[sum];
                y=i;
                for(int j=i+1;j<=n;j++)
                    scanf("%*d");
                break;
            }
        }
        printf("%d\n",y-x);
        for(int i=x+1;i<=y;i++)
            printf("%d\n",a[i]);
    }
    return 0;
}
