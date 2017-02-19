#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[2000];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,s=-1,t=-1;
    scanf("%d",&n);
    scanf("%s",str);
    if(strchr(str,'R')==NULL)
    {
        for(int i=0;str[i];i++)
        {
            if(str[i]=='L' && t==-1) t=i;
            if(str[i]=='L' && str[i+1]=='.')
            {
                s=i;
                break;
            }
        }
        printf("%d %d\n",s+1,t);
    }
    else if(strchr(str,'L')==NULL)
    {
        for(int i=0;str[i];i++)
        {
            if(str[i]=='R' && s==-1) s=i;
            if(str[i]=='R' && str[i+1]=='.')
            {
                t=i;
                break;
            }
        }
        printf("%d %d\n",s+1,t+2);
    }
    else
    {
        for(int i=0;str[i];i++)
        {
            if(str[i]=='R' && s==-1)  s=i;
            if(str[i]=='R' && str[i+1]=='L') t=i;
        }
        printf("%d %d\n",s+1,t+1);
    }
    return 0;
}





























