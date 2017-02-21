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


int win[5000000];
int main()
{
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j;
        scanf("%d%d",&n,&k);
        for(i=0;i<k;i++)
            win[i]=1;
        int top=0;
        for(i=k;win[i-1]<=n;i++)
        {
            while(top<i && win[top]*k<win[i-1]) top++;
            win[i]=win[i-1]+win[top];
        }
        bool flag=1;
        for(j=0;win[j]<=n;j++)
            if(win[j]==n)
            {
                flag=0;
                break;
            }
        if(flag)
        {
            for(;j>-1;j--)
                if(n==win[j]) break;
                else n%=win[j];
            printf("Case %d: %d\n",ti++,n);
        }
        else printf("Case %d: lose\n",ti++);
    }
    return 0;
}