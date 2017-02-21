#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
int mpn;
set<int> st[2][10005],ig;

inline int cv(int x)
{
    if(mp.count(x))
        return mp[x];
    else
        return mp[x]=++mpn;
}
inline void fn(int x,int y,int z)
{
    set<int>::iterator t=st[z][y].lower_bound(x),l=st[z][y].begin(),r=st[z][y].end();
    bool s;
    if(t==l&&t==r)
        s=0;
    else
    {
        r--;
        if(*t!=x||t!=l||t!=r)
            s=1;
        else
            s=0;
    }
    puts(s?"DENIED":"GRANTED");
    if(s)
        ig.insert(x);
    else
    {
        st[1][y].insert(x);
        if(z)
            st[0][y].insert(x);
    }
}

int main()
{
    char a[5];
    int x,y;

    while(~scanf("%s",a)&&a[0]!='#')
    {
        scanf("%d%d",&x,&y);
        y=cv(y);
        if(ig.count(x))
            puts("IGNORED");
        else
            fn(x,y,a[0]=='X');
    }
    return 0;
}
