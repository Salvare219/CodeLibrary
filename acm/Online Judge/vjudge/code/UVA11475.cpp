#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char str[1000005],pal[1000005];
int fail[1000005];
int main()
{
    int ti=1,t;
    fail[0]=-1;
    while(scanf("%s",str)==1)
    {
        int i=strlen(str)-1,j;
        for(j=0;str[j];j++) pal[j]=str[i-j];
        pal[j]=0;
        i=0;j=-1;
        while(pal[i])
        {
            while(j!=-1 && pal[i]!=pal[j]) j=fail[j];
            i++;j++;
            fail[i]=j;
        }
        i=j=0;
        while(str[i])
        {
            while(j!=-1 && str[i]!=pal[j]) j=fail[j];
            i++;j++;
        }
        printf("%s%s\n",str,pal+j);
    }
    return 0;
}
