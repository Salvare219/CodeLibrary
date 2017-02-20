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
 //   freopen("1.txt","r",stdin);
	int n,q,p;
	while(scanf("%d%d%d",&n,&p,&q)==3)
	{
		n=n%(p+q);
		if(n<=p && n>0) printf("LOST\n");
		else printf("WIN\n");
	}
    return 0;
}

