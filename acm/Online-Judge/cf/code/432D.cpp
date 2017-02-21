#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char str[100050];
int fail[100050];
int cnt[100050];
bool vis[100050];
vector<int>ans;
vector<int>gra[100050];
int dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<gra[s].size();i++)
    {
        cnt[s]+=dfs(gra[s][i]);
    }
    cnt[s]++;
    return cnt[s];
}
int main()
{
   // freopen("1.txt","r",stdin);
    int k,d;
    scanf("%s",str);
    int i=0,j=-1;
    fail[0]=-1;
    while(str[i])
    {
        while(j!=-1 && str[i]!=str[j]) j=fail[j];
        i++;j++;
        fail[i]=j;
    }
    i=1;j=0;
    int n=strlen(str);
    ans.push_back(n);
    while(i<=n)
    {
        while(j!=-1 && str[i]!=str[j])
        {
            if(i==n)
            {
                if(j!=0)ans.push_back(j);
            }
            j=fail[j];
        }
        i++;
        j++;
    }
    for(int i=1;i<=n;i++)
        gra[fail[i]].push_back(i);
    for(int i=0;i<=n;i++)
        if(vis[i]==0)dfs(i);
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i],cnt[ans[i]]);
    }
    return 0;
}

