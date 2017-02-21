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
  //  freopen("1.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		n%=m+1;
		if(n==0) printf("Rabbit\n");
		else printf("Grass\n");
	}
    return 0;
}

