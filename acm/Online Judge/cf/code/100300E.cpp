#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double csu[2000050],csd[2000050];
int main()
{
    //freopen("6.txt","w",stdout);

    csu[0]=csd[0]=cos(0);
    csu[1]=csd[1]=cos(0.5);
    for(int i=2;i<=2000005;i+=2)
    {
        double cb=cos(i/2.0);
        csu[i]=max(csu[i-2],cb);
        csd[i]=min(csd[i-2],cb);
    }
    for(int i=3;i<=2000005;i+=2)
    {
        double cb=cos(i/2.0);
        csu[i]=max(csu[i-2],cb);
        csd[i]=min(csd[i-2],cb);
    }
    char ss[20];
    int a=0,b=0,s;
    for(int i=0;i<3;i++)
    {
        scanf("%s",ss);
        if(ss[0]=='s')a++;
        else b++;
    }
    scanf("%s%d",ss,&s);
    double ma=-100,mi=100;
    if(a>=2)
    {
        for(int z=1;z<s-1;z++)
        {
            int m=s-z;
            double ca=2*sin(m/2.0)*csu[m-2],cb=2*sin(m/2.0)*csd[m-2];
            if(a==2)
            {
                ca+=cos(z);
                cb+=cos(z);
            }
            else
            {
                ca+=sin(z);
                cb+=sin(z);
            }
            ma=max(ma,ca);
            ma=max(ma,cb);
            mi=min(mi,cb);
            mi=min(mi,ca);
        }
    }
    else
    {
        for(int z=1;z<s-1;z++)
        {
            int m=s-z;
            double ca=2*cos(m/2.0)*csu[m-2],cb=2*cos(m/2.0)*csd[m-2];
            //printf("%lf %lf\n",csu[m-2],csd[m-2]);
            if(b==3)
            {
                ca+=cos(z);
                cb+=cos(z);
            }
            else
            {
                ca+=sin(z);
                cb+=sin(z);
            }
            ma=max(ma,ca);
            ma=max(ma,cb);
            mi=min(mi,cb);
            mi=min(mi,ca);
        }
    }
    if(ss[1]=='a')
        printf("%.14f\n",ma);
    else
        printf("%.14f\n",mi);
    return 0;
}
