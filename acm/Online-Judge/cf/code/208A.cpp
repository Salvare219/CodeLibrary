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


char str[300];
char ans[300][300];
int main()
{
	scanf("%s",str);
	char *p,*sta=str;
	int k=0;
	while((p=strstr(sta,"WUB")))
	{
		if(p==sta) sta=p+3;
		else 
		{
			int i;
			for(i=0;i<p-sta;i++)
			{
				ans[k][i]=*(sta+i);
			}
			ans[k++][i]=0;
			sta=sta+i;
		}
	}
	if(sta!=NULL)
	{
		int i=0;
		for(i=0;*(sta+i);i++)
			ans[k][i]=*(sta+i);
		ans[k][i]=0;
		k++;
	}
	printf("%s",ans[0]);
	for(int i=1;i<k;i++)
	{
		putchar(' ');
		for(int j=0;ans[i][j];j++)
			putchar(ans[i][j]);
	}
	putchar(10);
    return 0;
}