#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int a[6666];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        if(n==5)
        {
            int lim=1<<5;
            int ans=0;
            int tot=0;
            for(int i=0;i<5;i++)
                tot+=a[i];
            for(int i=0;i<lim;i++)
            {
                int con=0,sum=0;
                for(int j=0;j<5;j++)
                    if((1<<j)&i) con++,sum+=a[j];
                if(con==3)
                {
                    if(sum%1024==0) ans=max(ans,(tot-sum-1)%1024+1);
                }
            }
            printf("%d\n",ans);
        }
        else if(n==4)
        {
            int lim=1<<4;
            int ans=0;
            for(int i=0;i<lim;i++)
            {
                int con=0,sum=0;
                for(int j=0;j<4;j++)
                    if((1<<j)&i) sum+=a[j],con++;
                if(con==3)
                {
                    if(sum%1024==0) ans=1024;
                }
                if(con==2)
                {
                    ans=max(ans,(sum-1)%1024+1);
                }
            }
            printf("%d\n",ans);
        }
        else printf("1024\n");
    }
	return 0;
}
