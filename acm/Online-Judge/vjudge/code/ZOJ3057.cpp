#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



bool dp[305][305][305];
int main()
{
 //   freopen("1.txt","r",stdin);
    int a,b,c,lim;
    for(int i=0;i<301;i++)
        for(int j=0;j<301;j++)
            for(int k=0;k<301;k++)
            {
                if(dp[i][j][k]) continue;
                for(int z=i+1;z<301;z++)
                    dp[z][j][k]=1;
                for(int z=j+1;z<301;z++)
                    dp[i][z][k]=1;
                for(int z=k+1;z<301;z++)
                    dp[i][j][z]=1;
                lim=max(i,j);
                for(int z=301-lim;z>0;z--)
                    dp[i+z][j+z][k]=1;
                lim=max(i,k);
                for(int z=301-lim;z>0;z--)
                    dp[i+z][j][k+z]=1;
                lim=max(j,k);
                for(int z=301-lim;z>0;z--)
                    dp[i][j+z][k+z]=1;
            }
    while(scanf("%d%d%d",&a,&b,&c)==3)
        printf("%d\n",dp[a][b][c]);
    return 0;
}
