#include<cstdio>   
#include<cstring>   
#include<math.h>   
#include<stdlib.h>   
#include<algorithm>   
using namespace std;   


int num[250005],sum[250005];
int main()   
{   
	int n;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		int m=-200;
		for(int i=0;i<n;i++)
		{
			scanf("%d",num+i);
			if(i!=0) sum[i]=sum[i-1]+num[i];
			else sum[0]=num[0];
			if(num[i]>m) m=num[i];
		}
		if(m<=0) printf("%d\n",m);
		else
		{
			int temp=0,max=0;
			for(int i=1;i<n;i++)
			{
				if(sum[i]<sum[i-1]) 
				{
					if(sum[i-1]-temp>max) max=sum[i-1]-temp;
				}
				else 
				{
					if(temp>sum[i-1]) temp=sum[i-1];
				}
			}
			if(sum[n-1]-temp>max) max=sum[n-1]-temp;
			if(max)
			printf("%d\n",max);
		}
	}
    return 0;
}    