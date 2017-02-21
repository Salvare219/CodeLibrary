#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[55];
		scanf("%s",str);
		int len=strlen(str),flag=1;
		for(int i=0;i<len;i++)
			if(str[i]=='D') 
			{
				flag=0;
				break;
			}
		if(flag) printf("Possible\n");
		else printf("You shall not pass!\n");
	}
    return 0;
}