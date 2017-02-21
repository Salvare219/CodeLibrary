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


char str[2000];
int main()
{
	bool nn[200]={0};
	scanf("%s",str);
	for(int i=0;str[i];i++)
		nn[str[i]-'a']=1;
	int time=0;
	for(int i=0;i<30;i++)
		if(nn[i]==1) time++;
	if(time%2) printf("IGNORE HIM!\n");
	else printf("CHAT WITH HER!\n");
    return 0;
}