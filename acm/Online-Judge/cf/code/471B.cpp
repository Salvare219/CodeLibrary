#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


pair<int,int>a[20000],c[20000];
int f[50000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]=make_pair(x,i+1);
        f[i]=x;
    }
    sort(a,a+n);
    sort(f,f+n);
    int k=unique(f,f+n)-f;
    long long sum=1;
    int gg=0;
    for(int i=0;i<k;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(a[j].first==f[i])
                cnt++;
        sum*=cnt;
        if(sum>=3)
        {
            gg=1;
        }
    }
    if(gg)
    {
        puts("YES");
        int x,y;
        for(int i=0;i<n;i++)
            printf("%d ",a[i].second);putchar(10);
        for(int i=0;i<n;i++)
            if(a[i].first==a[i+1].first)
            {
                swap(a[i],a[i+1]);
                x=i;
                y=i+1;
                break;
            }
        for(int i=0;i<n;i++)
            printf("%d ",a[i].second);putchar(10);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(a[i].first==a[j].first&&i!=x&&j!=y)
                {
                    swap(a[i],a[j]);
                    break;
                }
        for(int i=0;i<n;i++)
            printf("%d ",a[i].second);putchar(10);
    }
    else puts("NO");
    return 0;
}
