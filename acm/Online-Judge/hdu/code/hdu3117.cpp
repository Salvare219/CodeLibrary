#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int fib[45];
void mult(int a[][2],int b[][2],int c[][2])
{
    int d[2][2]={0};
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                d[i][j]=(d[i][j]+(a[i][k]*b[k][j])%10000)%10000;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            c[i][j]=d[i][j];
}
void pow_mat(int a[][2],int k)
{
    int ii[2][2]={0};
    for(int i=0;i<2;i++)
        ii[i][i]=1;
    while(k)
    {
        if(k%2) mult(a,ii,ii);
        k/=2;
        mult(a,a,a);
    }
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            a[i][j]=ii[i][j];
}
double pow_sa(double fa,int k)
{
    double s=1.0,lim=1e20;
    while(k)
    {
        if(k&1)
        {
            s=s*fa;
            while(s>lim) s/=1000000000;
        }
        k>>=1;
        fa=fa*fa;
        while(fa>lim) fa/=1000000000;
    }
    return s;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    fib[1]=fib[2]=1;
    for(int i=3;i<40;i++)
        fib[i]=fib[i-1]+fib[i-2];
    double k=sqrt(5.0);
    while(scanf("%d",&n)==1)
    {
        if(n<40) printf("%d\n",fib[n]);
        else
        {
            int s[2][2]={1,1,1,0};
            pow_mat(s,n);
            int last=s[1][0];
            long double ans=k/5.0*(pow_sa((1+k)/2,n)-pow_sa((1-k)/2,n));
            while(ans>100000.0) ans/=10.0;
            int fir=(int)ans;
            printf("%d...%04d\n",fir/10,last);
        }
    }
    return 0;
}