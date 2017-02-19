#include <bits/stdc++.h>
using namespace std;


int a[5000];
int b[5000];
int com[5000];
int v[5000];
char s[5000];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),com[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&s);
        for(int j=0;s[j];j++)
            if(s[j]=='1')
            {
                com[find(i)]=find(j+1);
            }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++)
        if(v[i]==0)
        {
            ans.clear();
            for(int j=i;j<=n;j++)
                if(find(j)==find(i))
                {
                    v[j]=1;
                    ans.push_back(a[j]);
                }
            sort(ans.begin(),ans.end());
            int p=0;
            for(int j=i;j<=n;j++)
                if(find(j)==find(i))
                {
                    b[j]=ans[p++];
                }
        }
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
    putchar(10);
    return 0;
}
