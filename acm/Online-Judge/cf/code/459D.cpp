#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#include<map>
map<int,int>mp;
int ff[1000050];
int a[1000050];
int bit[1000050];
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
void updat(int x,int v)
{
    if(x==0)return ;
    while(x<1000005)bit[x]+=v,x+=x&-x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=n-1;i>-1;i--)
    {
        mp[a[i]]++;
        ff[i]=mp[a[i]];
        updat(ff[i],1);
    }
    long long ans=0;
    mp.clear();
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
        updat(ff[i],-1);
        int c=mp[a[i]];
        ans+=query(c-1);
    }
    printf("%I64d\n",ans);
    return 0;
}
