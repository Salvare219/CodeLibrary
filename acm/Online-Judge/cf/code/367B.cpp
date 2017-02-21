#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<map>
int a[200050],b[200050],l[200050];
map<int,int>mp;
unsigned long long prim[300050];
bool vis[3000005];
vector<int>ans;
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,p,k=0;scanf("%d%d%d",&n,&m,&p);
    for(int i=2;i<3000000;i++)
    {
        if(vis[i]==0)prim[k++]=i;
        for(int j=0;j<k&&i*prim[j]<3000000;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
    for(int i=0;i<n;i++)scanf("%d",a+i),l[i]=a[i];
    for(int i=0;i<m;i++)scanf("%d",b+i);sort(l,l+n);
    for(int i=0;i<n;i++)mp[l[i]]=i;
    unsigned long long sed=0;
    for(int i=0;i<m;i++)
        sed+=prim[mp[b[i]]]*b[i];
    for(int i=0;i<p;i++)
    {
        int con=0,j,len=m*p;
        unsigned long long hash=0;
        for(j=i;con<m&&j<n;j+=p,con++)
            hash+=prim[mp[a[j]]]*a[j];
        if(hash==sed)ans.push_back(i);
        for(;j<n;j+=p)
        {
            hash-=prim[mp[a[j-len]]]*a[j-len];
            hash+=prim[mp[a[j]]]*a[j];
            if(hash==sed)ans.push_back(j-len+p);
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]+1);putchar(10);
    return 0;
}
