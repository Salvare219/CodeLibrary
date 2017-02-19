#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;
set<string> st[100005];
int mpn;

inline int s2i(string x)
{
    if(mp.count(x))
        return mp[x];
    return mp[x]=mpn++;
}
inline void gao(string a,string b,string c)
{
    a+=' ';
    a+=b;
    int cn=s2i(c);
    st[cn].insert(a);
}

int main()
{
    int n;
    char a[25],b[25],c[25];
    map<string,int>::iterator t;
    for(scanf("%d",&n);n--;)
    {
        scanf("%s%s%s",a,b,c);
        gao(a,b,c);
    }
    for(t=mp.begin();t!=mp.end();t++)
        cout<<t->first<<' '<<st[t->second].size()<<endl;
    return 0;
}
