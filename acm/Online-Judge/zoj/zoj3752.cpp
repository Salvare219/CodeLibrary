#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

const double eps=1e-12;
inline double cal(int a,int b,int c)
{
    double p=(a+b+c)/2.0;
    double c1=p-a,c2=p-b,c3=p-c;
    if(c1>0&&c2>0&&c3>0)
        return sqrt(p*c1*c2*c3);
    else
        return 0.0;
}
int main()
{
    int a[5][5],te[5];
    while(~scanf("%d%d",&a[0][0],&a[0][1]))
    {
        for(int i=1;i<3;i++)
            scanf("%d%d",&a[i][0],&a[i][1]);
        double ans=cal(a[0][0]+a[0][1],a[1][0]+a[1][1],a[2][0]+a[2][1]);
        int a1,b1,c1;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j)
                {
                    int k=3-i-j;
                    a1=a[i][0]+a[j][0]+a[j][1];
                    b1=a[k][0]+a[k][1];
                    c1=a[i][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][1]+a[j][0]+a[j][1];
                    b1=a[k][0]+a[k][1];
                    c1=a[i][0];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][0];
                    b1=a[i][1];
                    c1=a[j][0]+a[j][1]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j)
                {
                    int k=3-i-j;
                    a1=a[i][0]+a[j][0];
                    b1=a[j][1];
                    c1=a[i][1]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][0]+a[j][1];
                    b1=a[j][0];
                    c1=a[i][1]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));

                    a1=a[i][1]+a[j][0];
                    b1=a[j][1];
                    c1=a[i][0]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][1]+a[j][1];
                    b1=a[j][0];
                    c1=a[i][0]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    
                    a1=a[i][0];
                    b1=a[j][0];
                    c1=a[i][1]+a[j][1]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][0];
                    b1=a[j][1];
                    c1=a[i][1]+a[j][0]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][1];
                    b1=a[j][0];
                    c1=a[i][0]+a[j][1]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                    a1=a[i][1];
                    b1=a[j][1];
                    c1=a[i][0]+a[j][0]+a[k][0]+a[k][1];
                    ans=max(ans,cal(a1,b1,c1));
                }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(i!=j)
                {
                    int k=3-i-j;
                    for(int cc=0;cc<2;cc++)
                    {
                        int ccc=1-cc;
                        for(int dd=0;dd<2;dd++)
                        {
                            int ddd=1-dd;
                            a1=a[i][1]+a[j][cc];
                            b1=a[j][ccc]+a[k][dd];
                            c1=a[k][ddd]+a[i][0];
                            ans=max(ans,cal(a1,b1,c1));
                        }
                    }
                }
            printf("%.12f\n",ans);
    }
    return 0;
}