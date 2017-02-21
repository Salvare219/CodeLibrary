#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>   
using namespace std;   
  
  
int main()   
{   
	int n,k,ge;
	scanf("%d%d",&n,&k);
	ge=k-n*3;
	if(ge>=0) printf("0\n");
	else
	{
		printf("%d\n",-ge); 
	}
    return 0;   
} 