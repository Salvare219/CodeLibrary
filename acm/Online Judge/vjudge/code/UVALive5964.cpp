#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

unsigned long long phi[5000050];
unsigned long long sig[5000050];
void cal()
{
	phi[1]=1;
	for(int i=2;i<5000005;i++)
	   if(!phi[i])
		   for(int j=i;j<5000005;j+=i)
			{
				if(!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
}
const int sb=5000001;
int main()
{
    int t,ti=1;scanf("%d",&t);
    cal();
    for(int i=1;i<sb;i++)
        phi[i]=phi[i]*i/2;
    for(int i=1;i<sb;i++)
        for(int j=i;j<sb;j+=i)
            sig[j]+=phi[i];
    for(int i=1;i<sb;i++)
        sig[i]=sig[i]*i+sig[i-1];
    while(t--)
    {
        int n;scanf("%d",&n);
        printf("Case %d: %llu\n",ti++,sig[n]);
    }
    return 0;
}
