#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[50000];
int sta[5000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    int ans=n+2;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
            sta[j]=0x3fffffff;
        int temp;
        bool f=1;
        for(int j=n-1;j>-1;j--)
        {
            temp=sta[0];
            pop_heap(sta,sta+i);
            if(temp<1)
            {
                f=0;
                break;
            }
            temp=min(temp-1,a[j]);
            sta[i-1]=temp;
            push_heap(sta,sta+i);
        }
        if(f)ans=min(ans,i);
    }
    printf("%d\n",ans);
    return 0;
}
