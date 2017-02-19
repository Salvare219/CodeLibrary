#include<bits/stdc++.h>
using namespace std;

long long pw[40];
int s[40],ss[40],sn;

void dfs(int d,int a,int b)
{
    if(d<0)
    {
        if(a==0&&b==0)
            memcpy(s,ss,sizeof(s)),sn++;
        return;
    }
    if((a==0||b==0)&&a+b)
        return;
    for(int i=0;i<=a&&1ll*pw[d]*i<=b;i++)
        ss[d]=i,dfs(d-1,a-i,b-pw[d]*i);
}

int main()
{
    int n,a,b,i,j;
    pw[0]=1;
    for(scanf("%d",&n);n--;)
    {
        scanf("%d%d",&a,&b);
        if(a<0||b<0)
            puts("IMPOSSIBLE");
        else if(a==0)
            puts(b?"IMPOSSIBLE":"0");
        else if(a==1)
            puts(b==1?"AMBIGUOUS":"IMPOSSIBLE");
        else
        {
            for(sn=i=0;pw[i++]<=b;)
                pw[i]=pw[i-1]*a;
            dfs(--i,a,b);
            if(!sn)
                puts("IMPOSSIBLE");
            else if(sn>1)
                puts("AMBIGUOUS");
            else
            {
                for(j=i;!s[--j];);
                for(j++;j--;)
                    printf("%d%c",s[j]," \n"[!j]);
            }
        }
    }
    return 0;
}
