#include<cstdio>   
#include<cstring>   
#include<math.h>   
#include<stdlib.h>   
#include<algorithm>   
using namespace std;   


long long cat[1001];
void cal()
{
	cat[2]=2;cat[1]=1;cat[0]=1;
	for(int i=2;i<1001;i++)
	{
		long long sum=0;
		for(int j=0;j<=i;j++)
			sum=(sum+cat[j]*cat[i-j])%1000000;
		cat[i+1]=sum;
	}
}
int main()   
{   
//	freopen("1.txt","r",stdin);
	cal();
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		printf("%lld\n",cat[n]);
	}
    return 0;
}    