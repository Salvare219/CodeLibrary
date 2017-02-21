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
        if(n<=1) puts("0");
        else
        {
            int i,ans=1;
            for(i=2;i*i<=n;i++)
                if(n%i==0) ans+=n/i+i;
            if((i-1)*(i-1)==n) ans-=i-1;
            printf("%d\n",ans);
        }
    }
	return 0;
}
