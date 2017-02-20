#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char str[1000050],fail[1000050];
int main()
{
    fail[0]=-1;
    while(scanf("%s",str)==1)
    {

        int i=0,j=-1;
        while(str[i])
        {
            while(j!=-1 && str[i]!=str[j]) j=fail[j];
            i++,j++;
            fail[i]=j;
        }
        printf("%d\n",i-j);
    }
    return 0;
}
