#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int ans[1000000];
int main()
{
//	freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        int k=0;
        for(int i=1;i*i<=n;i++)
            if(n%i==0)
            {
                ans[k++]=i;
                if(i!=n/i) ans[k++]=n/i;
            }
        sort(ans,ans+k);
        printf("%d",ans[0]);
        for(int i=1;i<k;i++)
            printf(" %d",ans[i]);
        putchar(10);
    }
	return 0;
}
