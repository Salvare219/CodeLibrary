//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;



int sum[1002][3002];
char s[1002];
int cnt[21][1002][3002];
int main()
{
    //printf("%d\n%d\n",(sizeof(s)+sizeof(sum)+sizeof(cnt))/1024,(int)sqrt(1000.0));
    //freopen("1.txt","r",stdin);
    int n,m,q;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        int len=m+n+n;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=len-i+1;j++)
                sum[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s+1);
            for(int j=1;j<=m;j++)
                sum[i][j+n]=sum[i][j+n-1]+(s[j]=='X');
            for(int j=n+m+1;j<=len;j++)
                sum[i][j]=sum[i][j-1];
        }
        int f=max(0,(int)sqrt(n)-10);
        for(int k=1;k<f;k++)
            for(int i=1;i<=n;i++)
                for(int j=len-i+1;j>=i;j--)
                {
                    int &a=cnt[k][i][j];
                    a=sum[i][j]-sum[i][j-1];
                    if(i-k>0)
                    {
                        a+=cnt[k][i-k][j+k]+cnt[k][i-k][j-k];
                        a+=sum[i-k][j+k-1]-sum[i-k][j-k];
                        if(i-k-k>0)a-=cnt[k][i-k-k][j];
                    }
                }
        for(int i=0;i<q;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            y+=n;
            if(z<f)
                printf("%d\n",cnt[z][x][y]);
            else
            {
                int h=0,l=0;
                for(int i=x;i>-1;i-=z,l+=z)
                    h+=sum[i][y+l]-sum[i][y-l-1];
                printf("%d\n",h);
            }
        }
    }
    return 0;
}
