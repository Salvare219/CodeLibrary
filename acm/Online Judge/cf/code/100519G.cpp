#include<bits/stdc++.h>
using namespace std;

int mn,v[200005],s[200005],ins[200005];
map<string,int> mp;

inline int sti(string& a)
{
    if(mp.count(a))
        return mp[a];
    return mp[a]=++mn;
}

int dfs(int x,int d)
{
    if(v[x]<=0)
        return -1;
    if(s[x])
        return -1;
    if(ins[x])
    {
        s[x]=d-ins[x];
        return x;
    }
    ins[x]=d;
    int y=v[x];
    int z=dfs(y,d+1);
    if(z>0)
    {
        s[x]=s[y];
        return z==x?-1:z;
    }
    s[x]=s[y]+1;
    return -1;
}

int main()
{
    //freopen("1.txt", "r", stdin);
    int n,ans,x,y,i;
    string s1,s2,s0,t;
    cin>>n;
    for(mn=0;n--;)
    {
        cin>>s0>>s1>>t>>t>>s2;
        s1+=s0;s2+=s0;
        x=sti(s1);y=sti(s2);
        v[x]=y;
    }
    for(ans=0,i=1;i<=mn;i++)
    {
        dfs(i,1);
        ans=max(ans,s[i]);
    }
    printf("%d\n",ans);
    return 0;
}
