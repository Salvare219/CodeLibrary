#include<stdio.h>   
#include<string.h>   
#include<stdlib.h>   
#include<algorithm>   
#include<math.h>  
using namespace std;   


char str[15],ans[15]={0};
int k=0,flag=0;
void find(int sta,int end,char fff)
{
	char max=0;
	int ss=-1,mark=-1;
	for(int i=sta;i<end;i++)
		if(str[i]>max)
		{
			mark=-1;
			ss=i+1;
			max=str[i];
		}
		else if(str[i]==max) mark=i;
	if(fff>max) return;
	else if(mark==-1)
	{
		ans[k++]=max;
		flag=1;
	}
	else
	{
		ans[k++]=max;
		find(ss,mark,max);
	}
}
int main()
{
	int len;
	scanf("%s",str);
	find(0,strlen(str),0);
	printf("%s",ans);
	len=strlen(ans);
	for(int i=(flag)?len-2:len-1;i>-1;i--)
	{
		putchar(ans[i]);
	}
	putchar(10);
    return 0;
}