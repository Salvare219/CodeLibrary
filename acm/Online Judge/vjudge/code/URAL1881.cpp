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


int main()
{
	int h,w,n,len;
	char str[280];
	scanf("%d%d%d",&h,&w,&n);
	getchar();
	int row=0,now=w,pag=0;
	for(int i=0;i<n;i++)
	{
		gets(str);
		len=strlen(str);
		if(now-len>=0) now-=len;
		else 
		{
			now=w-len;
			row++;
			if(row==h) 
			{
				pag++;
				row=0;
			}
		}
		now--;
	}
	printf("%d\n",pag+1);
    return 0;
}