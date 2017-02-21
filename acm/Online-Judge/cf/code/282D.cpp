#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[5];
int main()
{
 //   freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",num+i);
	if(n==2) 
	{
		if(num[1]<num[0]) swap(num[1],num[0]);
		double k=(1+sqrt(5.0))/2;
		n=num[1]-num[0];
		if(num[0]==(int)(k*n)) printf("BitAryo\n");
		else printf("BitLGM\n");
	}
	else 
	{
		if(num[0]^num[1]^num[2]) printf("BitLGM\n");
		else printf("BitAryo\n");
	}
    return 0;
}

