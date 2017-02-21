#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char s[]="1689";
int a[20][20];
char str[2000000];
int cnt[100];
int main()
{
//    freopen("1.txt","r",stdin);
    do
    {
        int c;
        sscanf(s,"%d",&c);
        for(int i=1,j=0;i<=100000;i*=10,j++)
            a[j][c*i%7]=c*i;
    }while(next_permutation(s,s+4));
    scanf("%s",str);
    for(int i=0;str[i];i++)
        cnt[str[i]-'0']++;
    cnt[1]--;cnt[6]--;cnt[8]--;cnt[9]--;
    int ans=0;
    for(int i=1;i<10;i++)
        for(int j=0;j<cnt[i];j++)
            putchar(i+'0'),ans=(ans*10+i)%7;
    int sb=cnt[0]+4;
    for(int i=0;i<sb;i++)
        ans=(ans*10)%7;
    int res=cnt[0]%6,cc=cnt[0]/6;
    printf("%d",a[res][(7-ans)%7]);
    for(int i=0;i<cc;i++)
        printf("000000");putchar(10);
    return 0;
}
