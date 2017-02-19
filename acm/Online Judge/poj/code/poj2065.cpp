#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


const int MAXN=80;

int a[MAXN][MAXN];
int x[MAXN];
int p;
inline void e_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;y=0;
        return ;
    }
    e_gcd(b,a%b,y,x);
    y-=a/b*x;
}
inline int lcm(int n,int m)
{
    int a=n,b=m,c=n%m;
    while(c)
    {
        a=b;b=c;
        c=a%b;
    }
    return n/b*m;
}
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r;
    int col=0;
    int ta,tb;
    int LCM,temp;
    for(i=0;i<=var;i++)
        x[i]=0;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        if(max_r!=k) for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
            if(a[i][col]!=0)
            {
                LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                ta=LCM/abs(a[i][col])%p;
                tb=LCM/abs(a[k][col])%p;
                if(a[i][col]*a[k][col]<0) tb=-tb;
                for(j=col;j<var+1;j++)
                    a[i][j]=(a[i][j]*ta-a[k][j]*tb)%p;
            }
    }
    for(i=var-1;i>-1;i--)
    {
        temp=a[i][var];
        for(j=i+1;j<var;j++)
            if(a[i][j]!=0) temp=(temp-a[i][j]*x[j])%p;
        e_gcd((a[i][i]+p)%p,p,ta,tb);
        temp=(temp+p)%p;
        ta*=temp;
        ta=(ta%p+p)%p;
        x[i]=ta;
    }
    return 0;
}
int main()
{
    int t;
    char str[80];
    scanf("%d",&t);
    while(t--)
    {
        int n,temp;
        scanf("%d%s",&p,str);
        n=strlen(str);
        for(int i=0;i<n;i++)
        {
            if(str[i]=='*') temp=0;
            else temp=str[i]-'a'+1;
            a[i][n]=temp%p;
            temp=1;
            for(int j=0;j<n;j++)
                a[i][j]=temp,temp=(i+1)*temp%p;
        }
        Gauss(n,n);
        printf("%d",x[0]);
        for(int i=1;i<n;i++)
            printf(" %d",x[i]);
        putchar(10);
    }
    return 0;
}

