#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


/*
int main()
{
    freopen("2.txt","r",stdin);
    int n,ti,len=1,las=0;
    double sum=0.0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ti);
        if(ti==1)
        {
            int x,a;
            scanf("%d%d",&a,&x);
            if(a==len) las+=x;
            sum=(sum*len+a*x)/len;
        }
        else if(ti==2)
        {
            int k;
            scanf("%d",&k);
            las=k;
            sum=(sum*len+k)/(len+1);
            len++;
        }
        else
        {
            sum=(sum*len-las)/(len-1);
            len--;
        }
        printf("%.7lf\n",sum);
    }
    return 0;
}*/


#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int n;
int pow_mod(int a,int b,int c)
{
    int d=1;
    while(b)
    {
        if(b%2) d=(d*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return d;
}
bool ok(int a)
{
    for(int i=1;i<n-1;i++)
        if(pow_mod(a,i,n)==1) return 0;
    if(pow_mod(a,n-1,n)==1) return 1;
    return 0;
}
int main()
{
 //  freopen("2.txt","r",stdin);
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        if(ok(i)) ans++;
    printf("%d\n",ans);
    return 0;
}

































