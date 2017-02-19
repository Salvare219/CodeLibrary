#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char s[100050];
int pn[100050]; //w
int pn2[100050]; //l
int sg[100050];
int trie[100050][27];
int cnt;
void add()
{
    int ind=0;
    for(int i=0;s[i];i++)
    {
        if(trie[ind][s[i]-'a']==0)
            trie[ind][s[i]-'a']=++cnt;
        ind=trie[ind][s[i]-'a'];
    }
}
void dfs(int s)
{
    int a=1,b=1,y,cnt=0;
    for(int i=0;i<26;i++)
        if(y=trie[s][i])
        {
            dfs(y);cnt++;
            a=min(pn[y],a);
            b=min(pn2[y],b);
        }
    if(cnt==0)
    {
        pn[s]=0;
        pn2[s]=1;
    }
    else
    {
        if(a==0)pn[s]=1;
        else pn[s]=0;
        if(b==0)pn2[s]=1;
        else pn2[s]=0;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        add();
    }
    dfs(0);
    if(pn[0]&&pn2[0])printf("First");
    else
    {
        if(pn[0]==0&&pn2[0]==0)printf("Second");
        else
        {
            if(pn[0])
            {
                if(k&1)printf("First");
                else printf("Second");
            }
            else printf("Second");
        }
    }
    return 0;
}
