#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int> >gra[500050];
vector<int>t;
vector<pair<int,int> >ans;
int ex[500050],ey[500050];
bool inv[500050];
int in[500050],out[500050];
bool v[500050];
int dfs(int s,int id)
{
    int y,cnt=0;
    v[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(v[y=gra[s][i].first]==0)
        {
           cnt+=dfs(y,gra[s][i].second);
        }
    if(in[s]%2==1&&out[s]%2==1)
        cnt++;
    if(id!=-1)
    {
        if(cnt&1)
            inv[id]^=1;
    }
    return cnt;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        gra[x].push_back(make_pair(y,i));
        gra[y].push_back(make_pair(x,i));
        ex[i]=x;ey[i]=y;
        inv[i]=0;
        out[x]++;
        in[y]++;
    }
    int cnt=0,f=0;
    for(int i=1;i<=n;i++)
        if(out[i]%2==0&&in[i]%2)
            t.push_back(i);
        else if(out[i]%2&&in[i]%2==0)
            t.push_back(i);
    int c=t.size()/2,cc=t.size();
    for(int i=0;i<c;i++)
    {
        ans.push_back(make_pair(t[i],t[cc-i-1]));
        out[t[i]]++;
        in[t[cc-i-1]]++;
    }
    for(int i=1;i<=n;i++)
        if(out[i]%2&&in[i]%2)
            cnt++,f=i;
    if(cnt)
    {
        if(cnt%2)
            ans.push_back(make_pair(f,f)),in[f]++,out[f]++;
        dfs(1,-1);
    }
    printf("%d\n",(int)ans.size()+m);
    for(int i=0;i<m;i++)
        if(inv[i]==0)
            printf("%d %d\n",ex[i],ey[i]);
        else
            printf("%d %d\n",ey[i],ex[i]);
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
