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


char str[4000];
int num[5000];
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s",str);
    for(int i=0;str[i];i++)
        if(str[i]>='0' && str[i]<='9') ;
        else str[i]=' ';
    char *p=str;
    int k=0,len;
    while((*p))
    {
        sscanf(p,"%d%n",num+k,&len);
        k++;p+=len;
    }
    sort(num,num+k);
    for(int i=0;i<k;i++)
    {
        if(i) printf("+%d",num[i]);
        else printf("%d",num[i]);
    }
    putchar(10);
	return 0;
}
