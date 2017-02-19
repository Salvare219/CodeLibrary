#include<bits/stdc++.h>
using namespace std;


pair<int,int>a[100050];
int bit[100050],sy[100050];
int query(int x)
{
    int s=0;
    while(x<100005)s+=bit[x],x+=x&-x;
    return s;
}
void updat(int x,int s)
{
    while(x)bit[x]+=s,x-=x&-x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("john.in","r",stdin);
    freopen("john.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i]=make_pair(x,y);
        sy[i]=y;
    }
    sort(sy,sy+n);
    int k=unique(sy,sy+n)-sy;
    sort(a,a+n);
    for(int i=0;i<n;i++)a[i].second=lower_bound(sy,sy+k,a[i].second)-sy+1;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=query(a[i].second+1);
        updat(a[i].second,1);
    }
    printf("%I64d\n",sum);
    return 0;
}
