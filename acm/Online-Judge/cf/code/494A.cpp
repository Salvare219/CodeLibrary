#include <bits/stdc++.h>
using namespace std;


char s[500050];
char t[500050];
int sum[500050];
int pos[500050];
int ans[500050];
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%s",s);
    int k=0,n=strlen(s),z=0;
    for(int i=0;i<n;i++)
        if(s[i]=='#')
        {
            t[k++]='#';
            pos[k-1]=z++;
            t[k++]=')';
        }
        else t[k++]=s[i];
    if(t[0]==')')sum[0]=-1;
    else if(t[0]=='(')sum[0]=1;
    else sum[0]=0;
    for(int i=1;i<k;i++)
        if(t[i]==')')sum[i]=sum[i-1]-1;
        else if(t[i]=='(')sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    int f=1;
    int cnt=0,has=0;
    for(int i=k-1;i>-1;i--)
        if(t[i]=='#')
        {
            if(sum[i]-has<0)f=0;
            ans[pos[i]]=sum[i]-has;
            has+=ans[pos[i]];
        }
        else if(t[i]==')')has++;
        else has--;
    for(int i=0;i<k;i++)
    {
        if(t[i]==')')cnt--;
        else if(t[i]=='(')cnt++;
        else cnt-=ans[pos[i]];
        if(cnt<0)f=0;
    }
    if(cnt!=0)f=0;
    if(f==0)puts("-1");
    else
    {
        for(int i=0;i<z;i++)
            printf("%d\n",ans[i]+1);
    }
    return 0;
}
