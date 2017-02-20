#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define INF 0x7fffffff


char str[100];
char wei[][20]={"hundred","thousand","million"};
int weii[3]={100,1000,1000000};
char num[][20]={"zero", "one", "two", "three", "four", "five", 
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve", 
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen", 
	"eighteen","nineteen","twenty", "thirty", "forty", 
	"fifty", "sixty", "seventy", "eighty","ninety"};
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		long long temp[100]={0};
		int flag=0,k=0;
		char ch=' ';
		while(ch!=10)
		{
			if(scanf("%s",str)==EOF) break;;
			ch=getchar();
			for(int i=0;i<3;i++)
				if(strcmp(str,wei[i])==0)
				{
					if(i>=flag)
					{
						temp[k]=temp[k]*weii[i];
						flag=i;
					}
					else 
					{
						temp[k+1]=temp[k]%(weii[flag]/10);
						temp[k]=temp[k]-temp[k+1];
						k++;
						temp[k]=temp[k]*weii[i];
						flag=i;
					}
				}
			for(int i=0;i<28;i++)
			{
				if(strcmp(str,num[i])==0)
				{
					if(i>19) 
					{
						temp[k]=temp[k]+(i/10+i%10)*10;
					}
					else 
					{
						temp[k]=temp[k]+i;
					}
				}
			}
		}
		long long sum=0;
		for(int i=0;temp[i];i++)
			sum=sum+temp[i];
		printf("%d\n",sum);
	}
    return 0;
}