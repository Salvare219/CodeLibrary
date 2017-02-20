#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int sg[40];
bool v[400];
int a[40];
int main()
{
    for(int i=1;i<30;i++)
    {
        memset(v,0,sizeof(v));
        for(int j=0;j<i;j++)
            for(int k=j;k<i;k++)
                v[sg[j]^sg[k]]=1;
        for(int j=0;;j++)
            if(v[j]==0)
            {
                sg[i]=j;
                break;
            }
    }
    int n,ti=1;
    while(scanf("%d",&n)&&n)
    {
        printf("Game %d: ",ti++);
        int sum=0;
        for(int i=n-1;i>-1;i--)
            scanf("%d",a+i),a[i]%2?sum^=sg[i]:0;
        bool fin=0;
        for(int i=n-1;i>-1&&!fin;i--)
            if(a[i])
            {
                for(int j=i-1;j>-1&&!fin;j--)
                    for(int k=j;k>-1&&!fin;k--)
                    {
                        int te=sum^sg[i]^sg[j]^sg[k];
                        if(te==0)
                        {
                            printf("%d %d %d\n",n-i-1,n-j-1,n-k-1);
                            fin=1;
                        }
                    }
            }
        if(!fin)puts("-1 -1 -1");
    }
    return 0;
}
