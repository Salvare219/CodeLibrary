//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")

vector<int>gra[100050];
vector<int>fl[100050];
int hs[100050],fa[100050],top[100050];
int dep[100050],cw[100050],totw;
int ta[100050];


struct tree
{
    int l,r,cnt;
    long long sum;
}h[2000000];
int rt[100050],tot;
void insert(int &f,int l,int r,int x)
{
    h[++tot]=h[f];f=tot;
    h[f].sum+=x;
    h[f].cnt++;
    if(l==r)return;
    int mid=(l+r+1)>>1;
    if(x>mid)insert(h[f].r,mid,r,x);
    else insert(h[f].l,l,mid-1,x);
}


int dfs(int s)
{
    int y,z=0,f=0,t,sum=1;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=fa[s])
        {
            dep[y]=dep[fa[y]=s]+1;
            ta[y]=fl[s][i];

            rt[y]=rt[s];
            insert(rt[y],0,10000,fl[s][i]);

            t=dfs(y);sum+=t;
            if(t>z)z=t,f=y;
        }
    return hs[s]=f,sum;
}
void build(int s)
{
    int y;
    cw[s]=++totw;
    if(y=hs[s])top[y]=top[s],build(y);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=fa[s]&&y!=hs[s])
            build(top[y]=y);
}

int num[100050];
int dp[100050][20];
int to[100050];
int n,m;
void rmq()
{
    for(int i=0;i<n;i++)dp[i][0]=num[i+1];
    for(int l=2,s=0;l<=n;l<<=1,s++)
        for(int i=0;i+l<=n;i++)
	    dp[i][s+1]=min(dp[i][s],dp[i+l/2][s]);
}
void pre_log()
{
    to[1]=0;
    for(int i=2;i<100005;i+=2)
        to[i]=to[i+1]=to[i>>1]+1;
}
long long query2(int l,int r)
{
    l--;r--;
    if(l>r) swap(l,r);
    int mid=to[r-l+1];
    int len=1<<mid;
    return min(dp[l][mid],dp[r-len+1][mid]);
}


long long query(int x,int y,long long k,long long a,long long b)
{
    int a1=rt[x],a2=rt[y],a3;
    int f1=top[x],f2=top[y],ct=0;
    long long sum=1ll<<60;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(f1,f2),swap(x,y);
        sum=min(sum,query2(cw[f1],cw[x]));
        x=fa[f1];f1=top[x];
    }
    if(dep[x]!=dep[y])
    {
        if(dep[x]<dep[y])swap(x,y);
        sum=min(sum,query2(cw[hs[y]],cw[x]));
    }
    a3=rt[y];
    if(a<=b)return sum+k/a;
    else
    {
        if(k>=a)sum+=1+(k-a)/b;
        long long l=0,r=10000,mid;
        long long s,cnt=0,s1,s2;
        while(l<r)
        {
            mid=(l+r+1)>>1;
            s1=s2=0;
            s1+=h[h[a1].l].cnt+h[h[a2].l].cnt-2*h[h[a3].l].cnt;
            s2+=h[h[a1].l].sum+h[h[a2].l].sum-2*h[h[a3].l].sum;
            s=(s1*mid-s2+(mid-l)*cnt)*b;
            if(s>k)
            {
                r=mid-1;
                a1=h[a1].l;
                a2=h[a2].l;
                a3=h[a3].l;
            }
            else
            {
                l=mid;
                a1=h[a1].r;
                a2=h[a2].r;
                a3=h[a3].r;
                cnt+=s1;
                k-=s;
            }
        }
        if(cnt>0)l+=k/(cnt*b);
        return max(sum,l);
    }
}
int main()
{
    int ti,ct=1;scanf("%d",&ti);pre_log();
    while(ti--)
    {
        int s,t,x,y,z;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            gra[i].clear(),fl[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            gra[x].push_back(y);fl[x].push_back(z);
            gra[y].push_back(x);fl[y].push_back(z);
        }
        dep[1]=1;totw=0;
        tot=0;
        dfs(1);
        top[1]=1;
        build(1);
        for(int i=1;i<=n;i++)
            num[cw[i]]=ta[i];
        rmq();
        printf("Case #%d:\n",ct++);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&s,&t,&x,&y,&z);
            printf("%I64d\n",query(s,t,x,y,z));
        }
    }
    return 0;
}
