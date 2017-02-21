#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


bool vis[205];
int num[205],nex[205],c[205];
char ans[205],str[205];
int n;
void pow_group(int k)
{
    int sta=1,len=1;
    for(int i=1;i<=n;i++)
    {
        if(sta==num[nex[i]])
        {
            for(int j=0;j<len;j++)
                c[nex[i-len+1+j]]=nex[i-len+1+(j+k)%len];
            len=1;
            sta=nex[i+1];
        }
        else len++;
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        for(int i=1;i<=n;i++)
            scanf("%d",num+i),vis[i]=0;
        int k=1,sta,now;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            sta=i;
            vis[i]=1;
            nex[k++]=i;
            now=num[i];
            while(sta!=now)
            {
                vis[now]=1;
                nex[k++]=now;
                now=num[now];
            }
        }
        int z=0;
        while(scanf("%d",&z))
        {
            if(z==0) break;
            gets(str);
            pow_group(z);
            int i;
            for(i=1;str[i];i++);
            for(;i<=n;i++) str[i]=' ';
            for(i=1;i<=n;i++) ans[c[i]-1]=str[i];
            ans[n]=0;
            for(i=0;i<n;i++)
                putchar(ans[i]);
            putchar(10);
        }
        putchar(10);
    }
    return 0;
}
