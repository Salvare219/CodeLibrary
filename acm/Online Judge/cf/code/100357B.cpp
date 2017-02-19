#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int> > q;
int a[505],b[505],h;
char s[505][505];

inline void G(int x,int y)
{
    s[x++][y]='+';
    if(h==1)
        return;
    for(int i=2;i<h;i++)
        s[x++][y]='|';
    s[x][y]='+';
}

int main()
{
    freopen("chip.in","r",stdin);
    freopen("chip.out","w",stdout);
    int n,nn,m,i,j,c,k;
    scanf("%d%d%d",&n,&m,&h);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    for(i=0;i<m;i++)
        scanf("%d",b+i),q.push(make_pair(b[i],i));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            s[i][j]='*';
    for(i=0,nn=n-h+1;i<nn;i++)
    {
        for(c=j=0;j<m;j++)
            if(s[i][j]=='*')
                c++;
        if(c<a[i])
            return puts("inconsistent");
        while(c>a[i])
        {
            if(q.empty())
                return puts("inconsistent");
            k=q.top().second;
            q.pop();
            if(b[k]<=0)
                return puts("inconsistent");
            b[k]--;
            G(i,k);
            c--;
        }
        for(c=j=0;j<m;j++)
            if(s[i][j]=='+'&&s[i+1][j]=='*')
                q.push(make_pair(b[j],j));
    }
    for(;i<n;i++)
    {
        for(c=j=0;j<m;j++)
            if(s[i][j]=='*')
                c++;
        if(c!=a[i])
            return puts("inconsistent");
    }
    for(i=0;i<m;i++)
        if(b[i]>0)
            return puts("inconsistent");
    for(i=0;i<n;i++)
        puts(s[i]);
    return 0;
}
