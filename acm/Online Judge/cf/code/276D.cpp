#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;




int main()
{
//	freopen("1.txt","r",stdin);
	long long l,r;
	scanf("%I64d%I64d",&l,&r);
	long long ans=0;
	for(int i=63;i>-1;i--)
	{
		if((l>>i)!=(r>>i)) 
		{
			i++;
			ans=1;
			while(i)
			{
				ans*=2;
				i--;
			}
			ans--;
			break;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}