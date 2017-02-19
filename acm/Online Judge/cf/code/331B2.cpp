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


int num[400000];
int to[400000];
int bit[401075];
void updat(int x,int v)
{
    while(x<401000)
    {
        bit[x]+=v;
        x+=x&-x;
    }
}
int query(int x)
{
    if(x==0) return 0;
    int s=0;
    while(x)
    {
        s+=bit[x];
        x-=x&-x;
    }
    return s;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",num+i);
        to[num[i]]=i;
    }
    to[n+1]=999999999;
    to[0]=-1;
    for(int i=1;i<=n;i++)
        if(to[i-1]>to[i])
            updat(i,1);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==1)
        {
            int a=query(z),b=query(y);
            printf("%d\n",query(z)-query(y)+1);
        }
        else
        {
            if(abs(num[y-1]-num[z-1])==1)
            {
                if(num[y-1]-1==num[z-1]) swap(y,z);
                if(to[num[y-1]]>to[num[y-1]+1])
                {
                    updat(num[y-1]+1,-1);
                }
                else
                {
                    updat(num[y-1]+1,1);
                }

                if(to[num[z-1]]>to[num[z-1]+1])
                {
                    if(to[num[y-1]]<=to[num[z-1]+1])
                        updat(num[z-1]+1,-1);
                }
                else
                {
                    if(to[num[y-1]]>=to[num[z-1]+1])
                        updat(num[z-1]+1,1);
                }
                if(to[num[y-1]]>to[num[y-1]-1])
                {
                    if(to[num[z-1]]<=to[num[y-1]-1])
                        updat(num[y-1],1);
                }
                else
                {
                    if(to[num[z-1]]>=to[num[y-1]-1])
                        updat(num[y-1],-1);
                }
            }
            else
            {
                if(num[y-1]>num[z-1]) swap(y,z);
                if(to[num[y-1]]>to[num[y-1]+1])
                {
                    if(to[num[z-1]]<=to[num[y-1]+1])
                        updat(num[y-1]+1,-1);
                }
                else
                {
                    if(to[num[z-1]]>=to[num[y-1]+1])
                        updat(num[y-1]+1,1);
                }
                if(to[num[z-1]]>to[num[z-1]+1])
                {
                    if(to[num[y-1]]<=to[num[z-1]+1])
                        updat(num[z-1]+1,-1);
                }
                else
                {
                    if(to[num[y-1]]>=to[num[z-1]+1])
                        updat(num[z-1]+1,1);
                }

                if(to[num[y-1]]>to[num[y-1]-1])
                {
                    if(to[num[z-1]]<=to[num[y-1]-1])
                        updat(num[y-1],1);
                }
                else
                {
                    if(to[num[z-1]]>=to[num[y-1]-1])
                        updat(num[y-1],-1);
                }
                if(to[num[z-1]]>to[num[z-1]-1])
                {
                    if(to[num[y-1]]<=to[num[z-1]-1])
                        updat(num[z-1],1);
                }
                else
                {
                    if(to[num[y-1]]>=to[num[z-1]-1])
                        updat(num[z-1],-1);
                }
            }
            swap(num[y-1],num[z-1]);
            to[num[y-1]]=y-1;
            to[num[z-1]]=z-1;
        }
    }
    return 0;
}

