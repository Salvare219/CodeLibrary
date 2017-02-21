#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


#include<map>
map<int,int>mp;
map<int,int>ans;
int ct[100050];
int com[100050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int cnt;
int col[100050];
#include<set>
set<int>ss[100050];
int n,a,b;
bool v[100050];
void solv(int s)
{
    if(v[mp[s]])return ;
    v[mp[s]]=1;
    ss[cnt].insert(s);
    if(mp[a-s])solv(a-s);
    if(mp[b-s])solv(b-s);
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",ct+i);
        mp[ct[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cnt++;
        solv(ct[i]);
    }
    for(int i=1;i<=cnt;i++)
    {
        int f1=1,f2=1;
        for(set<int>::iterator it=ss[i].begin();it!=ss[i].end();it++)
        {
            int d=*it;
            if(ss[i].find(a-d)==ss[i].end())
                f1=0;
            if(ss[i].find(b-d)==ss[i].end())
                f2=0;
        }
        if(f1==0&&f2==0)
        {
            puts("NO");
            return 0;
        }
        else if(f1)
        {
            for(set<int>::iterator it=ss[i].begin();it!=ss[i].end();it++)
            {
                int d=*it;
                ans[d]=0;
            }
        }
        else
        {
            for(set<int>::iterator it=ss[i].begin();it!=ss[i].end();it++)
            {
                int d=*it;
                ans[d]=1;
            }
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ",ans[ct[i]]);
    putchar(10);
    return 0;
}
