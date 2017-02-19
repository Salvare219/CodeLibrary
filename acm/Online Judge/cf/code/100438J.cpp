#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


int a[55];
int b[55];
pair<int,int>p[55],fi[55];
int op[55],fp[55];
int ans,star,fc,fl;
//map<pair<unsigned long long,unsigned long long>,bool>mp;
map<vector<int>,bool>mp;
const unsigned long long s1=13131,s2=100007;
pair<unsigned long long,unsigned long long> get_sa(int f[],int k)
{
    unsigned long long a=0,b=0;
    for(int i=0;i<k;i++)
    {
        a+=s1*f[i];
        b+=s2*f[i];
    }
    return make_pair(a,b);
}
void get(vector<int>&a,int f[],int k)
{
    a.clear();
    for(int i=0;i<k;i++)
        a.push_back(f[i]);
    sort(a.begin(),a.end());
}
void dfs(int c[],int k,int l)
{
    for(int i=0;i<k;i++)
        if(abs(c[i]-star)<ans)
        {
            fc=c[i];
            ans=abs(c[i]-star);
            fl=l;
            for(int j=0;j<l;j++)
            {
                p[j].first=fi[j].first;
                p[j].second=fi[j].second;
                op[j]=fp[j];
            }
        }
    if(k==1);
    else
    {
        for(int i=0;i<k;i++)
            for(int j=i+1;j<k;j++)
            {
                int g[6];
                int f=0;
                for(int z=0;z<k;z++)
                    if(z!=i&&z!=j)
                    {
                        g[f++]=c[z];
                    }
                if(c[i]>c[j])
                    fi[l]=make_pair(c[i],c[j]);
                else
                    fi[l]=make_pair(c[j],c[i]);
                g[f]=c[i]+c[j];
                vector<int>o;
                get(o,g,f+1);
                if(mp.count(o)==0)
                {
                    mp[o]=1;
                    fp[l]=0;
                    dfs(g,f+1,l+1);
                }
                if(abs(c[i]-c[j])!=0)
                {
                    g[f]=abs(c[i]-c[j]);
                    get(o,g,f+1);
                    if(mp.count(o)==0)
                    {
                        mp[o]=1;
                        fp[l]=1;
                        dfs(g,f+1,l+1);
                    }
                }
                g[f]=c[i]*c[j];
                get(o,g,f+1);
                if(mp.count(o)==0)
                {
                    mp[o]=1;
                    fp[l]=2;
                    dfs(g,f+1,l+1);
                }
                if(c[i]%c[j]==0)
                {
                    g[f]=c[i]/c[j];
                    get(o,g,f+1);
                    if(mp.count(o)==0)
                    {
                        mp[o]=1;
                        fp[l]=3;
                        dfs(g,f+1,l+1);
                    }
                }
                if(c[j]%c[i]==0)
                {
                    g[f]=c[j]/c[i];
                    get(o,g,f+1);
                    if(mp.count(o)==0)
                    {
                        mp[o]=1;
                        fp[l]=3;
                        dfs(g,f+1,l+1);
                    }
                }
            }
    }
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        for(int i=0;i<6;i++)
            scanf("%d",a+i);
        scanf("%d",&star);
        ans=100000;fc=-1;fl=-1;
        dfs(a,6,0);
        printf("Target: %d\n",star);
        for(int i=0;i<fl;i++)
        {
            int a=p[i].first,b=p[i].second;
            if(op[i]==0)
                printf("%d + %d = %d\n",a,b,a+b);
            if(op[i]==1)
                printf("%d - %d = %d\n",a,b,a-b);
            if(op[i]==2)
                printf("%d * %d = %d\n",a,b,a*b);
            if(op[i]==3)
                printf("%d / %d = %d\n",a,b,a/b);
        }
        printf("Best approx: %d\n\n",fc);
    }
    return 0;
}
