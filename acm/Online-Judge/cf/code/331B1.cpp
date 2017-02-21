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


int num[400000];
int to[400000];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",num+i),to[num[i]]=i;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)
        {
            int con=1;
            for(int i=y+1;i<=z;i++)
                if(to[i-1]>to[i]) con++;
            printf("%d\n",con);
        }
        else
        {
            swap(num[y-1],num[z-1]);
            to[num[y-1]]=y-1;
            to[num[z-1]]=z-1;
        }
    }
    return 0;
}


/*
int dp[1000050];
void cal(int n)
{
    dp[0]=0;
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        int c=i,b;
        while(c)
        {
            b=c%10;
            if(i-b>=0) dp[i]=min(dp[i-b]+1,dp[i]);
            c/=10;
        }
    }
}
int main()
{
    freopen("1.txt","r",stdin);
    int n;
    for(int i=0;i<500;i++)
    {
        cal(i);
        printf("%d ",dp[i]);
        if((i+1)%10==0) putchar(10);
    }
}*/
