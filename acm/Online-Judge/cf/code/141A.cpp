#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char lib[140];
int a[40];
char str[140];
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s",str);
    for(int i=0;str[i];i++)
        a[str[i]-'A']++;
    scanf("%s",str);
    for(int i=0;str[i];i++)
        a[str[i]-'A']++;
    scanf("%s",lib);
    for(int i=0;lib[i];i++)
        a[lib[i]-'A']--;
    for(int i=0;i<26;i++)
        if(a[i])
        {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");

    return 0;
}


