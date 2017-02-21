#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


const int MAXN=305;

int a[MAXN][MAXN];
int x[MAXN];
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
    int LCM;
    int temp;
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
                ta=LCM/abs(a[i][col]);
                tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0) tb=-tb;
                for(j=col;j<var+1;j++)
                    a[i][j]=(a[i][j]*ta-a[k][j]*tb)%7;
            }
    }
    for(i=k;i<equ;i++)
        if(a[i][var]!=0) return 1;
    if(k<var) return 2;
    for(i=var-1;i>-1;i--)
    {
        temp=a[i][var];
        for(j=i+1;j<var;j++)
            if(a[i][j]!=0) temp-=a[i][j]*x[j];
        for(j=3;j<10;j++)
            if((a[i][i]*j-temp)%7==0)
            {
                x[i]=j;
                break;
            }
        if(x[i]==0) return 1;
    }
    return 0;
}
char lib[][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
    int n,m;
    char s1[9],s2[9];
    while(scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0) break;
        int k,temp;
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++)
        {
            scanf("%d%s%s",&k,s1,s2);
            for(int j=0;j<7;j++)
            {
                if(strcmp(lib[j],s1)==0) s1[0]=j;
                if(strcmp(lib[j],s2)==0) s2[0]=j;
            }
            a[i][n]=s2[0]-s1[0]+1;
            for(int j=0;j<k;j++)
                scanf("%d",&temp),a[i][temp-1]++;
            for(int j=0;j<n;j++)
                a[i][j]%=7;
        }
        temp=Gauss(m,n);
        if(temp==1) puts("Inconsistent data.");
        else if(temp==2) puts("Multiple solutions.");
        else
        {
            printf("%d",x[0]);
            for(int i=1;i<n;i++)
                printf(" %d",x[i]);
            putchar(10);
        }
    }
    return 0;
}

