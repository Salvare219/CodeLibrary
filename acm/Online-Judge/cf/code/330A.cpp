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


char str[555][555];
int maz[555][555];
int main()
{
 //   freopen("1.txt","r",stdin);
    int r,c;
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++)
    {
        scanf("%s",str[i]);
    }
    int ans=0;
    for(int i=0;i<r;i++)
    {
        bool fl=0;
        for(int j=0;str[i][j];j++)
            if(str[i][j]=='S') fl=1;
        if(fl==0)
        {
            ans+=c;
            for(int j=0;str[i][j];j++)
                str[i][j]=0;
        }
    }
    for(int i=0;i<c;i++)
    {
        bool fl=0;
        for(int j=0;j<r;j++)
            if(str[j][i]=='S') fl=1;
        if(fl==0)
        {
            for(int j=0;j<r;j++)
                if(str[j][i]=='.') ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
