#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int n,T;
int M[10000],L[10000],K[10000];
int cnt[10000];
bool del[10000];
bool Judge(int tot)
{
    int t,i;
    memset(cnt,0,sizeof(cnt));
    memset(del,false,sizeof(del));
    cnt[0]=tot;
    int num=0;
    for(t=0;t<=T;t++)
    if(cnt[t])
    {
        for(int i=1;i<=n;i++)
        if(!del[i])
            if(t%(L[i]+K[i])<=L[i])
            {
                cnt[t]--;
                if(t+M[i]>T)
                    return false;
                num++;
                del[i]=true;
                cnt[t+M[i]]++;
                if(!cnt[t])
                    break;
            }
        cnt[t+1]+=cnt[t];
    }
    return num==n;
}
int main()
{
    while(scanf("%d%d",&n,&T)!=EOF)
    {
        if(!n && !T)
            break;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&M[i],&L[i],&K[i]);
        int r;
        for(int mid=0;mid<=n;mid++)
            if(Judge(mid))
            {
                r=mid;
                break;
            }
        printf("%d\n",r);
    }
    return 0;
}


