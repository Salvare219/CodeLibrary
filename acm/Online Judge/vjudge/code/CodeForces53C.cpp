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
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(i%2==0) printf("%d ",i/2+1);
		else printf("%d ",n-i/2);
	}
	putchar(10);
	return 0;
}