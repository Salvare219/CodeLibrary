#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char s[500050];
char b[500050];
long long h1[500050];
long long h2[500050];
int ma;
void updat(long long h1[],int l)
{
    h1[l]=1;
    ma=max(l,ma);
    if(h1[l]&&h1[l+1])
    {
        h1[l]--;
        h1[l+1]--;
        updat(h1,l+2);
    }
}
int cal(char s[],int n,long long h1[])
{
    for(int i=0;i<n;i++)
        h1[i]=s[n-i-1]-'0';
    ma=n;
    for(int i=n-1;i>0;i--)
        if(h1[i]&&h1[i-1])
        {
            h1[i]--;
            h1[i-1]--;
            updat(h1,i+1);
        }
    return ma;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%s%s",s,b);
    int n=strlen(s),m=strlen(b);
    n=cal(s,n,h1);
    m=cal(b,m,h2);
    int z=max(n,m);
    int fin=0;
    for(int i=z;i>-1;i--)
        if(h1[i]>h2[i])
        {
            fin=1;
            break;
        }
        else if(h1[i]<h2[i])
        {
            fin=2;
            break;
        }
    if(fin==0)puts("=");
    else if(fin==1)puts(">");
    else puts("<");
    return 0;
}
