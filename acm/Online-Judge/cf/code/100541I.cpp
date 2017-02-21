#include<bits/stdc++.h>
using namespace std;


char maz[1050][1050];
int d1[2][1050][1050];
int d2[2][1050][1050];
int d3[2][1050][1050];
int d4[2][1050][1050];
int n,m;
void cal1()
{
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            if(maz[i][j]=='0')
            {
                d1[0][i][j]=0;
                d1[1][i][j]=0;
            }
            else
            {
                d1[0][i][j]=d1[1][i-1][j]+1;
                d1[1][i][j]=d1[0][i][j+1]+1;
            }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=m;j++)
            if(maz[i][j]=='0')
            {
                d2[0][i][j]=0;
                d2[1][i][j]=0;
            }
            else
            {
                d2[0][i][j]=d2[1][i+1][j]+1;
                d2[1][i][j]=d2[0][i][j-1]+1;
            }
}
void cal2()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(maz[j][i]=='0')
            {
                d3[0][j][i]=0;
                d3[1][j][i]=0;
            }
            else
            {
                d3[0][j][i]=d3[1][j][i-1]+1;
                d3[1][j][i]=d3[0][j-1][i]+1;
            }
    for(int i=m;i>=1;i--)
        for(int j=n;j>=1;j--)
            if(maz[j][i]=='0')
            {
                d4[0][j][i]=0;
                d4[1][j][i]=0;
            }
            else
            {
                d4[0][j][i]=d4[1][j][i+1]+1;
                d4[1][j][i]=d4[0][j+1][i]+1;
            }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=m+1;j++)
            {
                maz[i][j]=0;
                d1[0][i][j]=0;
                d2[0][i][j]=0;
                d3[0][i][j]=0;
                d4[0][i][j]=0;
                d1[1][i][j]=0;
                d2[1][i][j]=0;
                d3[1][i][j]=0;
                d4[1][i][j]=0;
            }
        for(int i=1;i<=n;i++)
            scanf("%s",maz[i]+1);
        cal1();
        cal2();
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int z1=d1[0][i][j]+d2[0][i][j];
                int z2=d3[0][i][j]+d4[0][i][j];
                ans=max(ans,z1+z2-3);
            }
        printf("%d\n",ans);
    }
    return 0;
}
