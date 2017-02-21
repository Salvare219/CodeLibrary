#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;


int num[100005][3];
int xu[100005];
bool cmp(int a,int b)
{
    if(num[a][2]==num[b][2]) return num[a][1]<num[b][1];
    else return num[a][2]<num[b][2];
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&num[i][0],&num[i][1]);
            num[i][2]=(num[i][0]+num[i][1]+1)/2-1;
            xu[i]=i;
        }
        sort(xu,xu+n,cmp);
        bool flag=1;
        int now=(num[xu[0]][0]+num[xu[0]][1])/2+1;
        for(int i=1;i<n;i++)
        {
            if(now>num[xu[i]][2])
            {
                flag=0;
                break;
            }
            now=max(now+(num[xu[i]][1]-num[xu[i]][0])/2+1,(num[xu[i]][1]+num[xu[i]][0]+1)/2-1);
        }
        puts(flag?"YES":"NO");
    }
}