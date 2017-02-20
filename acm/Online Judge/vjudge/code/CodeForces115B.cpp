#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char maz[555][555];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i]);
    int now=0,ans=0;
    for(int i=0;i<n;i++)
    {
        //printf("%d %d\n",now,ans);
        if(i&1)
        {
            int to=m;
            for(int j=i;j<=i+1&&j<n;j++)
                for(int k=0;k<m;k++)
                    if(maz[j][k]=='W')
                        to=min(to,k);
            if(to==m);
            else
            {
                if(to<now)
                {
                    ans+=now-to;
                    now=to;
                }
            }
        }
        else
        {
            int to=-1;
            for(int j=i;j<=i+1&&j<n;j++)
                for(int k=0;k<m;k++)
                    if(maz[j][k]=='W')
                        to=max(to,k);
            if(to==-1);
            else
            {
                if(to>now)
                {
                    ans+=to-now;
                    now=to;
                }
            }
        }
    }
    int ff=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(maz[i][j]=='W')
                ff=max(ff,i);
    printf("%d\n",ans+ff);
	return 0;
}
