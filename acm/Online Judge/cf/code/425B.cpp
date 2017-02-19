#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[200][200];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    int sb=200;
    if(m<=10)
    {
        for(int i=0;i<(1<<m);i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                int cnt=0;
                for(int z=0;z<m;z++)
                    if(a[j][z]==(((1<<z)&i)>0))cnt++;
                sum+=min(cnt,m-cnt);
            }
            sb=min(sb,sum);
        }
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
                if(i!=j)
                {
                    int cnt=0;
                    for(int z=0;z<m;z++)
                        if(a[i][z]!=a[j][z])cnt++;
                    sum+=min(cnt,m-cnt);
                }
            sb=min(sb,sum);
        }
    }
    if(sb>k)printf("-1\n");
    else printf("%d\n",sb);
    return 0;
}
