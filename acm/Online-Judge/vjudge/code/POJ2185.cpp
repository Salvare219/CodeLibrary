#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char str[10050][80];
int fail[10050];
int dp[10050];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    int r,c,i,j,a=1,b=1;fail[0]=-1;
    scanf("%d%*d",&c);
    for(r=0;r<c;r++)
    {
        scanf("%s",str[r]);
        i=0,j=-1;
        while(str[r][i])
        {
            while(j!=-1 && str[r][i]!=str[r][j]) j=fail[j];
            i++,j++;
            fail[i]=j;
        }
        j=i-fail[i];
        a=a*j/gcd(a,j);
    }
    a=min(a,i);
    for(r=0;r<a;r++)
    {
        i=0,j=-1;
        while(i<c)
        {
            while(j!=-1 && str[i][r]!=str[j][r]) j=fail[j];
            i++,j++;
            fail[i]=j;
        }
        j=i-fail[i];
        b=b*j/gcd(b,j);
    }
    b=min(b,c);
    printf("%d\n",a*b);
    return 0;
}
