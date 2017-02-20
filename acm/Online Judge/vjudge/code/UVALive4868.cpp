#include<cstdio>   
#include<cstring>   
#include<math.h>   
#include<stdlib.h>   
#include<algorithm>   
using namespace std;   


char num[15];
int tran(int len,char a[])
{
	int sum=0;
	for(int i=0;i<len;i++)
		sum=sum*10+(a[i]-'0');
	return sum;
}
int pa(int len,int n,int flag)
{
	int temp,sum=0,m=1+9*flag;
	for(int i=flag;i<len;i++)
	{
		temp=(n%(m*10)-n%m)/m;
		sum=sum*10+temp;
		m*=10;
	}
	if(flag) m/=10;
	return sum+n*m;
}
int main()   
{   
	while(scanf("%s",num))
	{
		int len=strlen(num),i;
		if(len==1 && num[0]=='0') break;
		int cre=(len+1)/2,da=tran(len,num),max=1,k;
		for(i=0;i<cre;i++)
			max*=10;
		for(i=0;i<max;i++)
			if((k=pa(cre,i,len%2))>=da) 
				break;
		printf("%d\n",k-da);
	}
    return 0;
}    