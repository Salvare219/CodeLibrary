#include<bits/stdc++.h>
using namespace std;


char f[100000];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("black.in","r",stdin);
    freopen("black.out","w",stdout);
    int n,m,s,k;
    scanf("%d%d%d%d%s",&n,&m,&s,&k,f);
    int st=0,ok=1,cnt=0;
    for(int i=0;i<m;i++)
        if(f[i]=='*')
        {
            if(st==2)
            {
                ok=0;
                break;
            }
            else
            {
                st=1;
                cnt++;
            }
        }
        else
        {
            if(st==1)st=2;
        }
    if(ok==0)puts("Impossible");
    else
    {
        if(cnt==0)
        {
            int up=k-1,dw=n-k;
            if(up<s&&dw<s)puts("Impossible");
            else
            {
                if(s!=m)puts("Ambiguous");
                else
                {
                    if(up>s||dw>s)puts("Ambiguous");
                    else if(up==s&&dw==s)puts("Ambiguous");
                    else puts("Unique");
                }
            }
        }
        else
        {
            if(cnt!=s)puts("Impossible");
            else
            {
                int up=min(k-1,s-1),dw=min(n-k,s-1);
                if(up+dw+1==s)puts("Unique");
                else puts("Ambiguous");
            }
        }
    }
    return 0;
}
