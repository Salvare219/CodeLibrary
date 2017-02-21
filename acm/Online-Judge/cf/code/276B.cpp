#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[2000];
int num[30];
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%s",str);
	for(int i=0;str[i];i++)
	{
		num[str[i]-'a']++;
	}
	bool flag=1;
	int time=0;
	for(int i=0;i<26;i++)
	{
		if(num[i]%2) 
		{
			time++;
		}
	}
	if(time%2==1 || time==0) flag=1;
	else flag=0;
	if(flag) printf("First\n");
	else printf("Second\n");
	return 0;
}