#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;


struct p
{
    long long s,w;
    bool operator<(const p&a)const
    {
        return s+w<a.s+a.w;
    }
}s[50050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&s[i].w,&s[i].s);
    sort(s,s+n);
    long long nw=0,ans=-(1ll<<60);
    for(int i=0;i<n;i++)
    {
        ans=max(ans,nw-s[i].s);
        nw+=s[i].w;
    }
    printf("%I64d\n",ans);
    return 0;
}
