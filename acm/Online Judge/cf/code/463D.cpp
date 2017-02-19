#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int pos[5][1005];
int a[5][1005];
int dp[1005];
int n,k;
bool cmp(int x,int y)
{
    for(int i=1;i<k;i++)
        if(pos[i][x]>pos[i][y])return 0;
    return 1;
}
int main()
{
    //freopen("2.txt","w",stdout);
    int x;scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]),pos[i][a[i][j]]=j;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        for(int j=0;j<i;j++)
            if(cmp(a[0][j],a[0][i]))c=max(c,dp[j]);
        dp[i]=c+1;
        ans=max(ans,c+1);
    }
    printf("%d\n",ans);
    return 0;
}
