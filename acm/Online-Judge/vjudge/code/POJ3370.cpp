#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int pos[100050];
int main()
{
    int c,n;
    while(scanf("%d%d",&c,&n)&&n)
    {
        memset(pos,-1,sizeof(pos));
        int x,y,sum=0;pos[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            sum=(sum+x)%c;
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
        for(int i=x+1;i<=y;i++)
            printf("%d%c",i,i==y?10:32);
    }
    return 0;
}
