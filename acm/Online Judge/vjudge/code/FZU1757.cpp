#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[5][5],b[5][5],c[5][5],n,mod;
bool exam(int x[5][5],int y[5][5])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(x[i][j]!=y[i][j]) return 0;
    return 1;
}
void mult(int x[5][5],int y[5][5],int d[5][5])
{
    int f[5][5]={0};
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                f[i][j]=(f[i][j]+(x[i][k]*y[k][j])%mod)%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=f[i][j];
}
int main()
{
	while(scanf("%d%d",&n,&mod)==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&b[i][j]);
        int x;
        memset(c,0,sizeof(c));
        c[0][0]=c[1][1]=c[2][2]=c[3][3]=1;
        for(x=0;;x++)
        {
            if(exam(c,b)) break;
            else mult(c,a,c);
        }
        printf("%d\n",x);
    }
	return 0;
}
