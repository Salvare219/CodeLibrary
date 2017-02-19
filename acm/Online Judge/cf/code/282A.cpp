#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int sum=0;
    char str[20];
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(strchr(str,'+')!=NULL) sum++;
        else sum--;
    }
    printf("%d\n",sum);
    return 0;
}






