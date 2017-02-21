#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double a[50005][12],x[50005];
int n,m;
inline int Int()
{
    int a=0;char c=getchar();
    while(c<'0')c=getchar();
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
    return a;
}
double Gauss()
{
    int i,j,k;
    double temp;
    for(i=0;i<n-1;i++)
        for(j=1;j<=m;j++)
            if(fabs(a[i+j][m-j])>1e-6)
            {
                temp=a[i+j][m-j]/a[i][m];a[i+j][m-j]=0;
                for(k=m-j+1;k+j<=2*m;k++)
                    a[i+j][k]-=a[i][k+j]*temp;
                a[i+j][2*m+1]-=a[i][2*m+1]*temp;
            }
    x[n]=0;
    for(int i=n-1;i>-1;i--)
    {
        temp=a[i][2*m+1];
        for(int j=2*m;j>m;j--)
            temp-=a[i][j]*x[i+j-m];
        x[i]=temp/a[i][m];
    }
    return x[0];
}
int c[50005][6],sc[50005];
int main()
{
    while((n=Int())&&(m=Int()))
    {
        for(int i=0;i<n;i++)
            for(int j=sc[i]=1;j<=m;j++)
                sc[i]+=(c[i][j]=Int()),a[i][j]=0;n--;
        for(int i=0;i<n;i++)
        {
            double p=0;
            for(int j=max(i-m,0);j<i;j++)
                p+=(a[i][j-i+m]=0.3*c[i][i-j]/sc[i]);
            for(int j=min(i+m,n);j>i;j--)
                p+=(a[i][j-i+m]=0.7*c[i][j-i]/sc[i]);
            a[i][m]=-p;a[i][2*m+1]=-1.0;
        }
        printf("%.2f\n",Gauss());
    }
    return 0;
}
