#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str1[1000005],str2[1000005];
int main()
{
 //   freopen("1.txt","r",stdin);
	scanf("%s%s",str1,str2);
	if(strlen(str1)==strlen(str2))
	{
		if(strcmp(str1,str2)==0) printf("YES\n");
		else if(strchr(str1,'1')!=NULL && strchr(str2,'1')!=NULL) printf("YES\n");
		else printf("NO\n");
	}
	else printf("NO\n");
    return 0;
}

