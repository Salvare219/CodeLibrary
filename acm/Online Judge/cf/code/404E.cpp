#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[2000000];
int a[2000000];
int n,k;
bool ok(int st)
{
    int l=0,r=0,pos=0;
    bool f=1,ff=1;
    for(int i=0;i<k;i++)
    {
        pos+=a[i];
        if(st>0)pos=min(pos,st-1);
        else pos=max(pos,st+1);

        if(pos==r)f=1;
        else if(pos>r)
        {
            f=0;
            r=pos;
        }
        if(pos==l)ff=1;
        else if(pos<l)
        {
            ff=0;
            l=pos;
        }
    }
    if(pos==r&&f==0)return 1;
    else if(pos==l&&ff==0)return 1;
    else return 0;
}
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s",s);
    n=strlen(s);
    int now=0;k=0;
    long long l=0,r=0,pos=0,mid;
    bool f=1,ff=1;
    for(int i=0;i<n;i++)
        if(s[i]=='R')
        {
            pos++;
            if(pos==r)f=1;
            else if(pos>r)
            {
                f=0;
                r=pos;
            }
            if(now>=0)now++;
            else
            {
                a[k++]=now;
                now=1;
            }
        }
        else
        {
            pos--;
            if(pos==l)ff=1;
            else if(pos<l)
            {
                ff=0;
                l=pos;
            }
            if(now<=0)now--;
            else
            {
                a[k++]=now;
                now=-1;
            }
        }
    a[k++]=now;
    if(pos==r&&f==0)puts("1");
    else if(pos==l&&ff==0)puts("1");
    else
    {
        l=1;r=1000005;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(ok(mid))l=mid+1;
            else r=mid;
        }
        if(r!=1)printf("%d\n",r-1);
        else
        {
            l=1;r=1000005;
            while(l<r)
            {
                mid=(l+r)>>1;
                if(ok(-mid))l=mid+1;
                else r=mid;
            }
            if(r!=1)printf("%d\n",r-1);
            else puts("0");
        }
    }
    return 0;
}
