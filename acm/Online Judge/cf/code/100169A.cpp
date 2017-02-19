#include<bits/stdc++.h>
using namespace std;

vector<pair<int,pair<int,int> > > v[4005];
pair<unsigned long long,unsigned long long> d[4005];
queue<int> q;

inline void gao(int x)
{
    int i,j,y;
    pair<unsigned long long,unsigned long long> tmp;
    memset(d,-1,sizeof(d));
    d[x]=make_pair(0,0);
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0,j=v[x].size();i<j;i++)
        {
            y=v[x][i].first;
            tmp=make_pair(d[x].first+v[x][i].second.first,d[x].second+v[x][i].second.second);
            if(tmp<d[y])
                d[y]=tmp,q.push(y);
        }
    }
}

int main()
{
    int n,m,p,x,y,w,i;
    char z[5];
    pair<int,int> tmp;
    scanf("%d%d%d",&n,&m,&p);
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d%s",&x,&y,&w,z);
        if(z[0]=='I')
            tmp=make_pair(0,w);
        else
            tmp=make_pair(w,0);
        v[x].push_back(make_pair(y,tmp));
        v[y].push_back(make_pair(x,tmp));
    }
    while(p--)
    {
        scanf("%d%d",&x,&y);
        gao(x);
        if(d[y].first==-1)
            puts("IMPOSSIBLE");
        else
            printf("%I64u %I64u\n",d[y].first,d[y].second);
    }
    return 0;
}
