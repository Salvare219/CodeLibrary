#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//	freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        int ans=1,i;
        for(i=2;i*i<=n;i++)
            if(n%i==0) ans+=2;
        if((i-1)*(i-1)==n) ans--;
        printf("%d\n",ans);
    }
	return 0;
}
