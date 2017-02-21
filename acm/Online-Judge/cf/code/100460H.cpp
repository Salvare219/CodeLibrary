#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char lib[]="desmond";
char s[100050];
char t[1000];
int a[100050];
int main()
{
    int n,m,x;
    scanf("%s%d",s,&n);
    m=strlen(s);

    if(strstr(s,lib)!=NULL)
    {
        puts("I love you, Desmond!");
        printf("0");
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d%s",&x,t);
        s[x-1]=t[0];
        for(int j=max(0,x-7);j<min(m,x);j++)
        {
            int f=1;
            for(int k=0;k<7;k++)
                if(s[j+k]!=lib[k])
                {
                    f=0;
                    break;
                }
            if(f)
            {
                puts("I love you, Desmond!");
                printf("%d\n",i+1);
                return 0;
            }
        }
    }
    puts("Goodbye, my love!");
    return 0;
}

