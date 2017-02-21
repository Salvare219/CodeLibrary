#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char str[444][444];
bool vis[555];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    bool fa=1,ck=1;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        bool fl=0;
        for(int j=0;str[i][j];j++)
            if(str[i][j]=='.') fl=1,vis[j]=1;
        if(fl==0) fa=0;
    }
    for(int i=0;i<n;i++)
        if(vis[i]==0) ck=0;
    if(ck==0 && fa==0) printf("-1\n");
    else
    {
        if(fa==0)
        {
            for(int i=0;i<n;i++)
            {
                int ans;
                for(int j=0;j<n;j++)
                    if(str[j][i]=='.')
                    {
                        ans=j;
                    }
                printf("%d %d\n",ans+1,i+1);
            }
            putchar(10);
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                int ans;
                for(int j=0;j<n;j++)
                    if(str[i][j]=='.')
                    {
                        ans=j;
                    }
                printf("%d %d\n",i+1,ans+1);
            }
            putchar(10);
        }
    }
    return 0;
}
