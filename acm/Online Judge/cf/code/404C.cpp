#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>d[200000];
int a[200000],b[200000];
int main()
{
//    freopen("1.txt","r",stdin);
    long long n,k;
    int x;scanf("%I64d%I64d",&n,&k);
    int ma=0;
    for(int i=0;i<n;i++)scanf("%d",&x),d[x].push_back(i),ma=max(ma,x);
    long long las=1,how=0;
    bool f=1;
    for(int i=0;i<=ma;i++)
        if(d[i].size()==0)f=0;
    for(int i=0;i<=ma&&f;i++)
        if(d[i].size()>las)f=0;
        else
        {
            if(i==0)
            {
                las=k;
            }
            else
            {
                las=d[i].size()*(k-1);
                int con=d[i].size(),ll=1;
                if(i==1)ll=0;
                for(int j=0;j<d[i-1].size()&&con;j++)
                    for(int z=ll;z<k&&con;z++)
                    {
                        a[how]=d[i-1][j];
                        b[how++]=d[i][--con];
                    }
            }
        }
    if(f)
    {
        printf("%d\n",how);
        for(int i=0;i<how;i++)
            printf("%d %d\n",a[i]+1,b[i]+1);
    }
    else puts("-1");
    return 0;
}
