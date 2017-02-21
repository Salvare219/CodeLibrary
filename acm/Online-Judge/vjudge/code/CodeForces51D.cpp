#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[100500];
const double eps = 1e-6;
inline int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
int n;
int ok(double q)
{
    int cnt=0,cnt1=1;
    for(int i=1;i<n-1;i++)
        if(sgn(a[i]*q-a[i+1])!=0)cnt1=2;
    for(int i=0;i<n-1;i++)
        if(sgn(a[i]*q-a[i+1])!=0)
        {
            cnt++;
            if(i+2<n)
            {
                if(sgn(a[i]*q-a[i+2])==0)i++;
                else cnt++;
            }
        }
    return min(cnt,cnt1);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    int f=0;
    for(int i=0;i<n;i++)
        if(a[i]==0)f++;
    if(f)
    {
        if(f==1)
        {
            if(n==1)puts("0");
            else if(n==2)
            {
                if(a[0]==0)puts("1");
                else puts("0");
            }
            else if(n==3)puts("1");
            else
            {
                double q;
                if(a[0]==0)
                {
                    q=1.0*a[2]/a[1];
                }
                else
                {
                    if(a[1]==0)
                    {
                        q=1.0*a[n-1]/a[n-2];
                    }
                    else q=1.0*a[1]/a[0];
                }
                int c=ok(q);
                if(c>=2)puts("2");
                else if(c==1)puts("1");
                else puts("0");
            }
        }
        else
        {
            int c=ok(0.0);
            if(c>=2)puts("2");
            else if(c==1)puts("1");
            else puts("0");
        }
    }
    else
    {
        if(n<=2)puts("0");
        else if(n==3)
        {
            double q=1.0*a[1]/a[0];
            double q1=1.0*a[2]/a[1];
            if(sgn(q-q1)==0)puts("0");
            else puts("1");
        }
        else
        {
            double q;
            f=2;
            double qq[5]={1.0*a[1]/a[0],1.0*a[2]/a[1],1.0*a[3]/a[2]};
            for(int i=0;i<3;i++)
                f=min(ok(qq[i]),f);
            printf("%d\n",f);
        }
    }
	return 0;
}
