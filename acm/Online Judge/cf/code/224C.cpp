#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;


char str[100006];
char stack[100006];
int num[100006];
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%s",str);
	int imax=0,end=-1,k=0,fina=0;
	for(int i=0;str[i];i++)
	{
		if(str[i]=='(' || str[i]=='[') 
		{
			stack[k]=str[i];
			num[k++]=imax;
			imax=0;
		}
		else if(str[i]==')')
		{
			if(stack[k-1]=='(') 
			{
				imax+=num[k-1];
				k--;
			}
			else 
			{
				imax=0;
				k=0;
			}
		}
		else 
		{
			if(stack[k-1]=='[') 
			{
				imax+=num[k-1];
				k--;
				imax++;
			}
			else 
			{
				imax=0;
				k=0;
			}
		}
		if(imax>fina)
		{
			fina=imax;
			end=i;
		}
	}
	if(end==-1) printf("0\n\n");
	else 
	{
		int temp=fina;
		k=0;
		for(int i=end;i>-1;i--)
		{
			if(str[i]==')' || str[i]==']') stack[k++]=str[i];
			else 
			{
				if(str[i]=='[') temp--;
				k--;
			}
			if(temp==0 && k==0) 
			{
				temp=i;
				break;
			}
		}
		str[end+1]=0;
		printf("%d\n%s\n",fina,str+temp);
	}
	return 0;
}