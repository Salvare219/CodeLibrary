#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
#include<map>
using namespace std;   


int num[100050];
int stack[100050];
int main()
{
	int t=0;
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("Case %d: ",++t);
		int top=0;
		int time=0;
		stack[top++]=0;
		for(int i=0;i<n;i++)
			scanf("%d",num+i);
		for(int i=0;i<n;i++)
		{
			if(num[i]>stack[top-1])
			{
				stack[top++]=num[i];
				time++;
			}
			else if(num[i]<stack[top-1])
			{
				while(num[i]<stack[top-1])
				{
					top--;
				}
				if(num[i]>stack[top-1]) time++;
				stack[top++]=num[i];
			}
		}
		printf("%d\n",time);
	}
    return 0;
}