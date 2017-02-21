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
	int n;
	scanf("%d",&n);
	int min,flag=0,ans=1,temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(i==0) min=temp;
		else
		{
			if(min>temp) 
			{
				min=temp;
				flag=0;
				ans=i+1;
			}
			else if(min==temp)
			{
				flag=1;
			}
		}
	}
	if(flag) printf("Still Rozdil\n");
	else printf("%d\n",ans);
    return 0;
}