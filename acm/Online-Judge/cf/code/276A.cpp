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
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=-2000000000;
	for(int i=0;i<n;i++)
	{
		int f,t,temp;
		scanf("%d%d",&f,&t);
		if(t>k) temp=f-t+k;
		else temp=f;
		if(temp>ans) ans=temp;
	}
	printf("%d\n",ans);
	return 0;
}