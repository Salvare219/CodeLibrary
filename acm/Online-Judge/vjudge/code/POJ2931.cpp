#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[100];
long long sn(int n)
{
	long long k=1,ans=0;
	int i=0;
	k=k<<51;
	while(num[i]==num[0] && i<n) 
		if(num[i++]==1) ans+=k;
		else ans-=k;
	while(i<n)
	{
		k/=2;
		if(num[i++]==1) ans+=k;
		else ans-=k;
	}
	return ans;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	char name[10],ha[5];
	scanf("%d",&t);
	while(t--)
	{
		int la;
		scanf("%s%d",name,&la);
		int a[3];
		long long s[2]={0};
		for(int k=0;k<2;k++)
		{
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<a[i];j++)
				{
					scanf("%s",ha);
					if(ha[0]=='W') num[j]=1;
					else num[j]=0;
				}
				s[k]+=sn(a[i]);
			}
		}
		if(s[0]>=s[1]) printf("%s %d: Yes\n",name,la);
		else printf("%s %d: No\n",name,la);
	}
	return 0;
}