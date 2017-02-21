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
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=i;
	if(sum%2) printf("grimy\n");
	else printf("black\n");
	return 0;
}