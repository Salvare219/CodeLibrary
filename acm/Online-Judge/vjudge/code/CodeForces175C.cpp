#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

pair<long long,long long>a[500];
int main()
{
    long long n,x,y;
    scanf("%I64d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&x,&y),a[i]=make_pair(y,x);
    sort(a,a+n);
    int t,p=0;
    scanf("%d",&t);
    long long sum=0,s;y=0;
    for(int i=0;i<t;i++)
    {
        scanf("%I64d",&x);s=x;
        x=x-y;
        while(p<n&&a[p].second<x)
        {
            x-=a[p].second;
            sum+=1ll*a[p].second*(i+1)*a[p].first;p++;
        }
        if(p<n)
        {
            a[p].second-=x;
            sum+=1ll*x*(i+1)*a[p].first;
        }
        y=s;
    }
    while(p<n)
        sum+=1ll*a[p].second*(t+1)*a[p].first,p++;
    printf("%I64d\n",sum);
	return 0;
}