#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[1000005];
int nex[1000005];
int main()
{
    scanf("%s",str);
    nex[0]=-1;
    int i=0,j=-1;
    while(str[i])
    {
        while(j!=-1 && str[i]!=str[j]) j=nex[j];
        i++;j++;
        nex[i]=j;
    }
    int ans=nex[i],k=i;
    bool flag=0;
    while(ans>0)
    {
        for(j=1;j<i;j++)
            if(nex[j]==nex[k])
            {
                str[nex[k]]=0;
                printf("%s\n",str);
                return 0;
            }
        k=ans;
        ans=nex[ans];
    }
    printf("Just a legend\n");
    return 0;
}