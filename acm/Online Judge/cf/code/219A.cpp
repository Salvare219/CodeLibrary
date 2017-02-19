#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
#define INF 0x7fffffff


int mm[30]={0};
char temp[10000];
int main()
{
//	freopen("3.txt","r",stdin);
	int ks;
	char str[10000];
	scanf("%d",&ks);
	scanf("%s",str);
	for(int i=strlen(str)-1;i>-1;i--)
		mm[str[i]-'a']++;
	bool flag=0;
	int k=0;
	for(int i=0;i<26;i++)
	{
		if(mm[i]%ks!=0)  flag=1;
		else 
		{
			int a=mm[i]/ks;
			while(a--) temp[k++]=i+'a';
		}
	}
	temp[k]=0;
	if(flag) printf("-1\n");
	else 
	{
		for(int i=0;i<strlen(str);i+=k)
			printf("%s",temp);
		putchar(10);
	}
	return 0;
}