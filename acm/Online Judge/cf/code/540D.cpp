#include<bits/stdc++.h>
using namespace std;


bool v[105][105][105][3];
double dp[105][105][105][3];
double dfs(int i,int j,int k,int f)
{
    if(i==0)
    {
        if(f==0)return 1.0;
        else return 0.0;
    }
    if(j==0)
    {
        if(f==1)return 1.0;
        else return 0.0;
    }
    if(k==0)
    {
        if(f==2)return 1.0;
        else return 0.0;
    }
    if(v[i][j][k][f])return dp[i][j][k][f];
    v[i][j][k][f]=1;
    int num=i+j+k;
    int c12=i*j,c23=j*k,c13=i*k;
    int tot=c12+c23+c13;
    double p12=1.0*c12/tot,p23=1.0*c23/tot,p13=1.0*c13/tot;
    double sum=p12*dfs(i,j-1,k,f)+p23*dfs(i,j,k-1,f)+p13*dfs(i-1,j,k,f);
    return dp[i][j][k][f]=sum;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int x,y,z;scanf("%d%d%d",&x,&y,&z);
    printf("%.10f %.10f %.10f\n",dfs(x,y,z,2),dfs(x,y,z,0),dfs(x,y,z,1));
    return 0;
}

