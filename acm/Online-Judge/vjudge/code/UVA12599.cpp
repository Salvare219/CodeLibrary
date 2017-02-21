#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[70000];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        int i=0,k;
        while(s[i]=='B')i++;
        k=i;
        if(i==0)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        bool f=0;
        while(s[i]=='W')i++,f=1;
        if(f==0)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        if(i==n)
        {
            printf("1\n%d",n);
            for(int j=0;j<n;j++)
                printf(" %d",j+1);
            putchar(10);
        }
        else
        {
            if(s[n-1]=='B')puts("IMPOSSIBLE");
            else
            {
                printf("2\n");
                int sum=0;
                for(int j=0;j<n;j++)
                    if(s[j]=='W')sum++;
                printf("%d",sum-1+k);
                for(int j=0;j<k;j++)printf(" %d",j+1);
                for(int j=0;j<n-1;j++)
                    if(s[j]=='W')printf(" %d",j+1);
                printf("\n%d",n-sum+1-k);
                for(int j=k;j<n;j++)
                    if(s[j]=='B')printf(" %d",j+1);
                printf(" %d\n",n);
            }
        }
    }
    return 0;
}
