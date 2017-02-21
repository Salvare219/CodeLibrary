#include<bits/stdc++.h>
using namespace std;

int p[100000],pn,pn2;
int z[100005];
bool vis[100005];
map<int,int> mp;
vector<pair<int,int> > a[100005];
int ct[1000000][2];
int cct[1000000];

inline int get(int x)
{
    if(!mp.count(x))
        cct[mp[x]=pn2++]=x;
    return mp[x];
}

inline void cal(long long &ans,int a,int b)
{
    for(int i=0;ans<=10000000000ll&&i<b;i++)
        ans*=a;
}

int main()
{
    int n,m,x,i,j,k,c;
    long long ans,ans2;
    for(i=2;i<100001;i++)
    {
        if(vis[i]==0) p[pn++]=i;
        for(j=0;j<pn && p[j]*i<100005;j++)
        {
            vis[p[j]*i]=1;
            if(i%p[j]==0) break;
        }
    }
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&z[i]);
        for(x=z[i],j=0;1ll*p[j]*p[j]<=x;j++)
        {
            if(x%p[j]==0)
            {
                c=0;
                while(x%p[j]==0)
                    x/=p[j],c++;
                k=get(p[j]);
                a[i].push_back(make_pair(k,c));
                if(c>ct[k][1])
                    ct[k][1]=c;
                if(c>ct[k][0])
                    ct[k][1]=ct[k][0],ct[k][0]=c;
            }
        }
        if(x>1)
        {
            k=get(x);
            c=1;
            a[i].push_back(make_pair(k,c));
            if(c>ct[k][1])
                ct[k][1]=c;
            if(c>ct[k][0])
                ct[k][1]=ct[k][0],ct[k][0]=c;
        }
    }
    for(i=0;i<n;i++)
    {
        sort(a[i].begin(),a[i].end());
        a[i].push_back(make_pair(-1,-1));
        for(ans=1,k=j=0;j<pn2;j++)
        {
            c=ct[j][0];
            if(a[i][k].first==j)
            {
                if(a[i][k].second==ct[j][0])
                    c=ct[j][1];
                k++;
            }
            cal(ans,cct[j],c);
            if(ans>10000000000ll)
                break;
        }
        if(j<pn2)
            puts("Never");
        else if(ans%z[i]==0)
            puts("Never");
        else
        {
            ans2=((-m)%ans+ans)%ans;
            if((ans2+m)%z[i]==0)
                ans2+=ans;
            if(ans2<=1000000000ll)
                printf("%I64d\n",ans2);
            else
                puts("Never");
        }
    }
    return 0;
}
