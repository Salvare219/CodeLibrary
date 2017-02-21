#include<bits/stdc++.h>
using namespace std;



int deg[555];
vector<int>gra[555];
char s[200][200];
int v[500];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    scanf("%s",s[0]);
    int f=0;
    for(int i=1;i<n;i++)
    {
        scanf("%s",s[i]);
        int len=max(strlen(s[i]),strlen(s[i-1]));
        for(int j=0;j<len;j++)
            if(s[i][j]==s[i-1][j]);
            else
            {
                if(s[i][j]==0)f=1;
                else if(s[i-1][j]==0);
                else gra[s[i-1][j]-'a'].push_back(s[i][j]-'a'),deg[s[i][j]-'a']++;
                break;
            }
    }
    if(f)puts("Impossible");
    else
    {
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<26;i++)
            if(deg[i]==0)
                q.push(i),ans.push_back(i),v[i]=1;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            for(int i=0;i<gra[x].size();i++)
            {
                int y=gra[x][i];deg[y]--;
                if(deg[y]==0)
                {
                    q.push(y);v[y]=1;
                    ans.push_back(y);
                }
            }
        }
        for(int i=0;i<26;i++)
        {
            if(deg[i]!=0)f=1;
            if(v[i]==0)ans.push_back(i);
        }
        if(f)puts("Impossible");
        else
        {
            for(int i=0;i<26;i++)
                printf("%c",ans[i]+'a');
            puts("");
        }
    }
    return 0;
}
