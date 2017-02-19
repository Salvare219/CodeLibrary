#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   


int main()
{
	int t,sum=0,temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&temp);
		sum+=temp;
	}
	printf("%lf\n",(double)sum/(100*t)*100);
    return 0;
}