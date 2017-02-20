#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char str[1005];
int a[1005][1005];
int cro[1005],lin[1005][2];
int cross(int i,int d,int x)
{
    double x0=1.0*(lin[i][0]-d+lin[i][1]*lin[i][1]-x*x)/(2*lin[i][1]-2*x);
    if(x0>0) x0=(int)x0;
    else x0=(int)x0-1.0;
    return (int)x0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[i][j]=10000000;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        for(int j=0;j<m;j++)
            if(str[j]=='1') a[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        int x=10000,y=10000;
        for(int j=0;j<m;j++)
        {
            if(!a[i][j]) x=j;
            if(!a[i][m-j-1]) y=j;
            a[i][j]=min(a[i][j],(j-x)*(j-x));
            a[i][m-j-1]=min(a[i][m-j-1],(j-y)*(j-y));
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,k=1;
        lin[0][0]=0;lin[0][1]=-10000;
        cro[0]=-10000;
        for(int j=0;j<n;j++)
            if(a[j][i]<10000000)
            {
                while(cross(k-1,a[j][i],j)<cro[k-1]) k--;
                x=cross(k-1,a[j][i],j);
                cro[k]=max(0,x);
                lin[k][0]=a[j][i];
                lin[k++][1]=j;
            }
        cro[k]=n+5;k=1;
        for(int j=0;j<n;j++)
        {
            while(j==cro[k+1]+1) k++;
            a[j][i]=min(a[j][i],lin[k][0]+(lin[k][1]-j)*(lin[k][1]-j));
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(j==m-1) printf("%d\n",a[i][j]);
            else printf("%d ",a[i][j]);
    return 0;
}
