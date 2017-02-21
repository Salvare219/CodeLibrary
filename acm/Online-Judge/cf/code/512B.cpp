#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;



unordered_map<int,int>mp,mp2;
int l[500];
int c[500];
pair<int,int>p[500];
inline int gcd(int a,int b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,x;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&x),p[i].first=x;
    for(int i=0;i<n;i++)
        scanf("%d",&x),p[i].second=x;
    //sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        mp.clear();
        for(unordered_map<int,int>::iterator it=mp2.begin();it!=mp2.end();++it)
        {
            int a=it->first,b=it->second;
            int c=gcd(a,p[i].first);
            if(mp.count(a)!=0)
                mp[a]=min(mp[a],b);
            else
                mp[a]=b;
            if(mp.count(c)!=0)
                mp[c]=min(mp[c],b+p[i].second);
            else
                mp[c]=b+p[i].second;
        }
        x=p[i].first;
        if(mp.count(x)!=0)
            mp[x]=min(mp[x],p[i].second);
        else
            mp[x]=p[i].second;
        mp2=mp;
    }
    if(mp.count(1)==0)puts("-1");
    else printf("%d\n",mp[1]);
    return 0;
}
