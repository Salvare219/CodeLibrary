#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;




char str[1000];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,len;
	scanf("%d",&n);
	char *a=str;
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		len=strlen(a);
		a[len]=' ';
		a+=len+1;
	}
	a[0]=0;
	for(int i=0;i<26;i++)
		if(strchr(str,'a'+i)==NULL) 
		{
			printf("%c\n",i+'a');
			return 0;
		}
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
		{
			char num[3]={i+'a',j+'a'};
			if(strstr(str,num)==NULL) 
			{
				printf("%s\n",num);
				return 0;
			}
		}
	return 0;
}