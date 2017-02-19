#include <bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
using namespace tr1;

map<unsigned long long,int>mp;
int px[100050],py[100050],xi[100050];
const int mod=1000000009;
struct bit_tree
{
    int bit[100050],s;
    inline void updat(int x,int v)
    {
        while(x<100005) bit[x]+=v,x+=x&-x;
    }
    inline int find(int x)
    {
        int cnt=0,ans=0,p=1<<18;
        while(p)
        {
            ans|=p;
            if(ans>100001||cnt+bit[ans]>=x)ans^=p;
            else cnt+=bit[ans];p>>=1;
        }
        return ans+1;
    }
}b;
int ans[100050];
int inq[100050];
int del[100050];
int sz;
int dx[]={-1,0,1,-1,0,1};
int dy[]={1,1,1,-1,-1,-1};
unsigned long long get(long long x,long long y)
{
    return ((x+1000000000)<<30)+y;
}
void in(int f)
{
    inq[f]=1;
    b.updat(f,1);
    sz++;
}
void out(int f)
{
    inq[f]=0;
    b.updat(f,-1);
    sz--;
}
vector<int>up[100050],dw[100050];
bool can(int f)
{
    int y;
    for(int i=0;i<up[f].size();i++)
        if(del[y=up[f][i]]==0&&xi[y]==1)
            return 0;
    return 1;
}
void cal(int f)
{
    int y,z;
    del[f]=1;b.updat(f,-1);sz--;
    for(int i=0;i<up[f].size();i++)
        if(del[y=up[f][i]]==0)
        {
            xi[y]--;
            if(xi[y]==1)
                for(int j=0;j<dw[y].size();j++)
                    if(del[z=dw[y][j]]==0&&inq[z]&&!can(z))
                        out(z);
        }
    for(int i=0;i<dw[f].size();i++)
        if(del[y=dw[f][i]]==0&&inq[y]==0&&can(y))
            in(y);
}
int main()
{
    //freopen("2.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        px[i]=x;py[i]=y;
        mp[get(x,y)]=i;
    }
    for(int j=1;j<=n;j++)
    {
        int x=px[j],y=py[j],x1,y1;
        for(int i=0;i<3;i++)
        {
            x1=x+dx[i];y1=y+dy[i];
            if(mp[get(x1,y1)])
            {
                int f=mp[get(x1,y1)];
                up[j].push_back(f);
                dw[f].push_back(j);
                xi[f]++;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(can(i))
            in(i);
    int k=0,cnt=1;
    while(cnt<=n)
        if(cnt&1)
        {
            cnt++;
            int f=b.find(sz);
            ans[k++]=f;
            cal(f);
        }
        else
        {
            cnt++;
            int f=b.find(1);
            ans[k++]=f;
            cal(f);
        }
    long long sum=0;
    for(int i=0;i<n;i++)
        sum=(sum*n+ans[i]-1)%mod;
    printf("%d\n",(int)sum);
    return 0;
}
