#include<bits/stdc++.h>
using namespace std;


bool tri(int a,int b,int c)
{
    return a+b>c&&a+c>b&&b+c>a;
}
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
bool ok(long long a,long long b,long long c,long long p,long long q,long long r)
{
    if(tri(a,b,p)&&tri(b,c,q)&&tri(c,a,r)&&tri(p,r,q))
    {
        double x1=(b*b+a*a-p*p)/(2.0*b);
        double x2=(b*b+c*c-q*q)/(2.0*b);
        double h1=sqrt(a*a-x1*x1);
        double h2=sqrt(c*c-x2*x2);
        double ma=sqrt((h1+h2)*(h1+h2)+(x1-x2)*(x1-x2)),mi=sqrt((h1-h2)*(h1-h2)+(x1-x2)*(x1-x2));
        if(sgn(ma-r)>0&&sgn(r-mi)>0)
            return 1;
        else
            return 0;
    }
    else return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int a[10],c[10];
        for(int i=0;i<6;i++)
            scanf("%d",a+i);
        int ans=1;
        for(int i=0;i<6&&ans;i++)
            for(int j=i+1;j<6&&ans;j++)
                for(int k=j+1;k<6&&ans;k++)
                {
                    int f=0;
                    for(int z=0;z<6;z++)
                        if(z!=i&&z!=j&&z!=k)
                            c[f++]=a[z];
                    sort(c,c+f);
                    do
                    {
                        if(ok(a[i],a[j],a[k],c[0],c[1],c[2]))
                        {
                            ans=0;
                            break;
                        }
                    }while(next_permutation(c,c+f));
                }
        puts(ans?"NO":"YES");
    }
    return 0;
}
