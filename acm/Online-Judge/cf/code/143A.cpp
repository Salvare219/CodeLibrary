#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


bool vis[100];
int main()
{
//    freopen("1.txt","r",stdin);
    int r1,r2,d1,d2,c1,c2;
    scanf("%d%d%d%d%d%d",&r1,&r2,&c1,&c2,&d1,&d2);
    for(int i=1;i<=9;i++)
    {
        vis[i]=1;
        for(int j=1;j<=9;j++)
        {
            if(vis[j]) continue;
            vis[j]=1;
            for(int k=1;k<=9;k++)
            {
                if(vis[k]) continue;
                vis[k]=1;
                for(int z=1;z<=9;z++)
                {
                    if(vis[z]) continue;
                    if(i+j==r1 && k+z==r2 && i+k==c1 && j+z==c2 && i+z==d1 && j+k==d2)
                    {
                        printf("%d %d\n%d %d\n",i,j,k,z);
                        return 0;
                    }
                }
                vis[k]=0;
            }
            vis[j]=0;
        }
        vis[i]=0;
    }
    printf("-1\n");
    return 0;
}


