#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char str[100050];
char sta[100050];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s",str);
    int k=0;
    for(int i=0;str[i];i++)
    {
        sta[k++]=str[i];
        while(k>1 && sta[k-1]==sta[k-2]) k-=2;
    }
    if(k) printf("No\n");
    else printf("Yes\n");
    return 0;
}


