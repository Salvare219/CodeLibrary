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


int mat[35][35];
int ans[35];
int n;
int gauss()
{
    int fl,ac=0;
    for(int i=0;i<n;i++)
    {
        fl=-1;
        for(int j=i;fl==-1 && j<n;j++)
            if(mat[j][i]) fl=j;
        if(fl==-1)
        {
            ac++;continue;
        }
        if(fl!=i) for(int j=0;j<n+1;j++) swap(mat[i][j],mat[fl][j]);
        for(int j=i+1;j<n;j++)
            if(mat[j][i]) for(int z=i;z<n+1;z++) mat[j][z]^=mat[i][z];
    }
    for(int i=n-1;i>-1;i--)
    {
        fl=mat[i][n];
        for(int j=n-1;j>i;j--)
            if(mat[i][j]) fl^=ans[j];
        if(mat[i][i]) ans[i]=fl;
        else
        {
            if(fl) return -1;
        }
    }
    return ac;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++)
            scanf("%d",&mat[i][n]),mat[i][i]=1;
        int x,y;
        for(int i=0;i<n;i++)
            scanf("%d",&x),mat[i][n]^=x;
        while(scanf("%d%d",&x,&y))
        {
            if(x==0) break;
            mat[y-1][x-1]=1;
        }
        int temp=gauss();
        if(temp!=-1) printf("%d\n",1<<temp);
        else printf("Oh,it's impossible~!!\n");
    }
    return 0;
}
