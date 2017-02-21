#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



char str[1000005];
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%s",str);
	int now1=0,now0=0,i=0,ans=0;
	bool flag=0;
	while(str[i])
	{
		while(str[i])
		{
			if(str[i]=='1') now1++;
			else break;
			i++;
		}
		while(str[i])
		{
			if(str[i]=='0') now0++;
			else break;
			i++;
		}
		if(now1>1) 
		{
			if(flag) ans++;
			else ans+=2;
			flag=1;
		}
		if(now1==1) ans++;
		if(now0>=2) flag=0;
		now1=0;
		now0=0;
	}
	printf("%d\n",ans);
    return 0;
}