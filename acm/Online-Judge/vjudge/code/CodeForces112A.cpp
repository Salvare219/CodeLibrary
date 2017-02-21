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


int main()
{
    char a[555],b[555];
    scanf("%s%s",a,b);
    for(int i=0;a[i];i++)
        if(a[i]>='a') a[i]-=32;
    for(int i=0;b[i];i++)
        if(b[i]>='a') b[i]-=32;
    printf("%d",strcmp(a,b));
    return 0;
}
