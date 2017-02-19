#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int phi[1000005];
long long sum[1000005];
void cal()
{
    phi[1]=1;
    for(int i=2;i<1000001;i++)
        if(phi[i]==0)
        {
            for(int j=i;j<1000001;j+=i)
            {
                if(phi[j]==0) phi[j]=j;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    for(int i=2;i<1000001;i++)
        sum[i]=sum[i-1]+phi[i];
}
int main()
{
//	freopen("1.txt","r",stdin);
	cal();
	int n;
    while(scanf("%d",&n) && n)
    {
        printf("%lld\n",sum[n]);
    }
	return 0;
}
