#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char a[1000];
char ans[1000];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s",a);
    int k=0;
    bool fl=0;
    if(a[0]=='-') fl=1;
    ans[k++]='$';
    int i=fl,dot;
    for(;a[i];i++)
        if(a[i]=='.')
        {
            dot=k;
            ans[k++]='.';i++;
            break;
        }
        else ans[k++]=a[i];
    if(a[i]==0)
    {
        dot=k;
        ans[k++]='.';
        ans[k++]='0';
        ans[k++]='0';
    }
    else
    {
        ans[k++]=a[i];
        if(a[i+1]==0) ans[k++]='0';
        else ans[k++]=a[i+1];
    }
    ans[k++]=0;
    if(fl) putchar('(');
    i=0;
    while(ans[i])
    {
        if((dot-i)%3==0 && i!=0 && i!=1 && i!=dot) putchar(',');
        putchar(ans[i]);i++;
    }
    if(fl) putchar(')');
    putchar(10);
    return 0;
}


