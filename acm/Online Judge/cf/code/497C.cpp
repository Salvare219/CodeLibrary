#include <bits/stdc++.h>
using namespace std;


struct p
{
    int x,y,i;
    bool operator<(const p&a)const
    {
        if(x==a.x)return y<a.y;
        else return x<a.x;
    }
}c[200050];
struct p2
{
    int x,y,k,i;
    bool operator<(const p2&a)const
    {
        if(x==a.x)return y<a.y;
        else return x<a.x;
    }
}d[200050];
struct p3
{
    int r,k,i;
    p3(){}
    p3(int r_,int k_,int i_){r=r_;k=k_;i=i_;}
    bool operator<(const p3&a)const
    {
        if(r==a.r)return i<a.i;
        else return r<a.r;
    }
};
set<p3>s;
int ans[200050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&c[i].x,&c[i].y),c[i].i=i;
    sort(c,c+n);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&d[i].x,&d[i].y,&d[i].k),d[i].i=i;
    sort(d,d+m);
    int ps=0,f=1;
    for(int i=0;i<n;i++)
    {
        while(ps<m&&c[i].x>=d[ps].x)
        {
            s.insert(p3(d[ps].y,d[ps].k,d[ps].i));
            ps++;
        }
        set<p3>::iterator it=s.lower_bound(p3(c[i].y,-1,-1));
        if(it==s.end())
        {
            f=0;
            break;
        }
        else
        {
            ans[c[i].i]=it->i;
            if((it->k)>1)
            {
                p3 temp=(*it);
                temp.k--;
                s.erase(it);
                s.insert(temp);
            }
            else
            {
                s.erase(it);
            }
        }
    }
    if(f==0)puts("NO");
    else
    {
        puts("YES");
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]+1);
        putchar(10);
    }
    return 0;
}
