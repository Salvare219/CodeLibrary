#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[10000];
bool v[5000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    int ans=0;
    bool f=1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int ss=0,t=0;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='G')ss=j;
            if(s[j]=='S')t=j;
        }
        if(t<ss)f=0;
        else v[t-ss]=1;
    }
    if(f)
    {
        for(int i=0;i<=m+5;i++)
            ans+=v[i];
        printf("%d\n",ans);
    }
    else puts("-1");
    return 0;
}
