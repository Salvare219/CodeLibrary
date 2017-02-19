#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


map<int,int> p;
int num[400000];
long long sum[400000];
int a[400000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",num+i);
        p[num[i]]=i;
        sum[i+1]=sum[i]+max(0,num[i]);
    }
    long long ans=0x3fffffff;
    ans*=ans;
    ans=-ans;
    int fl;
    for(int i=0;i<n;i++)
    {
        if(p[num[i]]==i) continue;
        if(ans<sum[p[num[i]]]-sum[i+1]+num[i]*2)
        {
            int c=p[num[i]];
            ans=sum[p[num[i]]]-sum[i+1]+num[i]*2;
            fl=i;
        }
    }
    printf("%I64d ",ans);
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(i<fl) a[k++]=i;
        else if(i>p[num[fl]]) a[k++]=i;
        else
        {
            if(i==fl || i==p[num[fl]]) continue;
            if(num[i]<0) a[k++]=i;
        }
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++)
        if(i) printf(" %d",a[i]+1);
        else printf("%d",a[i]+1);
    putchar(10);
    return 0;
}
