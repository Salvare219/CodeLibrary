#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    int f,w;
    bool operator<(p a)const{return w<a.w;}
}c[100005],g[100005];
#include<map>
map<int,int>mp;
map<int,int>::iterator it;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&c[i].f,&c[i].w);
        for(int i=0;i<m;i++)
            scanf("%d%d",&g[i].f,&g[i].w);
        sort(c,c+n);sort(g,g+m);
        int p=m-1;
        bool f=0;mp.clear();
        long long ans=0;
        for(int i=n-1;i>-1;i--)
        {
            while(g[p].w>=c[i].w)mp[g[p--].f]++;
            it=mp.lower_bound(c[i].f);
            if(it==mp.end()){f=1;break;}
            ans+=it->first;
            if(--it->second==0)mp.erase(it);
        }
        if(f)puts("-1");
        else printf("%lld\n",ans);
    }
    return 0;
}
