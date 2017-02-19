#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[500];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",num+i);
    sort(num,num+n);
    printf("1 %d\n",num[0]);
    int flag=0;
    for(int i=n-1;i>-1;i--)
        if(num[i]<=0)
        {
            flag=i;
            break;
        }
    int s=1;
    if(n-flag-1==0)
    {
        s+=2;
        printf("2 %d %d\n",num[1],num[2]);
    }
    else
    {
        printf("%d",n-flag-1);
        for(int i=flag+1;i<n;i++)
            printf(" %d",num[i]);
        putchar(10);
    }
    printf("%d",flag-s+1);
    for(int i=s;i<=flag;i++)
        printf(" %d",num[i]);
    putchar(10);
    return 0;
}
