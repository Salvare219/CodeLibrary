#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    long long n;
    while(scanf("%I64d",&n)==1)
    {
        long long ans=n,a=1,b=n;
        long long fa=4*n+1,cc;
        cc=sqrt(fa);
        if((cc-1)%2==0) fa=(cc-1)/2;
        else fa=cc/2;
        if(fa*fa+fa==n)
        {
            if(2*fa<ans) ans=2*fa,a=2,b=fa;
        }
        int lim=(int)(pow(1.0*n,0.4)+0.5);
        for(int i=2;i<=lim;i++)
        {
            long long sum=0,kr=i;
            int j;
            for(j=0;sum<n;j++)
            {
                sum+=kr;
                kr*=i;
            }
            if(sum==n)
            {
                if(ans>(long long)i*j) ans=(long long)i*j,a=j,b=i;
            }
        }
        n--;
        if(ans>n) ans=n,a=1,b=n;
        fa=4*n+1;
        cc=sqrt(fa);
        if((cc-1)%2==0) fa=(cc-1)/2;
        else fa=cc/2;
        if(fa*fa+fa==n)
        {
            if(2*fa<ans) ans=2*fa,a=2,b=fa;
        }
        lim=(int)(pow(1.0*n,0.4)+0.5);
        for(int i=2;i<=lim;i++)
        {
            long long sum=0,kr=i;
            int j;
            for(j=0;sum<n;j++)
            {
                sum+=kr;
                kr*=i;
            }
            if(sum==n)
            {
                if(ans>(long long)i*j) ans=(long long)i*j,a=j,b=i;
            }
        }
        printf("%I64d %I64d\n",a,b);
    }
	return 0;
}
