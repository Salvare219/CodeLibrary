#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char a[]="1",b[]="14",c[]="144";
char str[50000];
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s",str);
    int i=0;
    while(str[i])
    {
        if(str[i]=='1')
        {
            i++;
            if(str[i]=='4')
            {
                i++;
                if(str[i]=='4')
                {
                    i++;
                }
                else continue;
            }
            else continue;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

