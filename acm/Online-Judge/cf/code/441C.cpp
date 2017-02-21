#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int x[100000],y[100000],cnt;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        if(i%2)
        {
            for(int j=1;j<=m;j++)
            {
                x[cnt]=i;
                y[cnt++]=j;
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                x[cnt]=i;
                y[cnt++]=j;
            }
        }
    }
    int tot=0;
    for(int i=1;i<k;i++)
    {
        printf("2 %d %d %d %d\n",x[tot],y[tot],x[tot+1],y[tot+1]);
        tot+=2;
    }
    printf("%d",cnt-tot);
    for(int i=tot;i<cnt;i++)
    {
        printf(" %d %d",x[i],y[i]);
    }
    return 0;
}
