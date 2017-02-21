#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[200];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s",s);
    int a=0,b=0,c=0,i;
    for(i=0;s[i];i++)
        if(s[i]>='0'&&s[i]<='9')a=1;
        else if(s[i]>='a'&&s[i]<='z')b=1;
        else if(s[i]>='A'&&s[i]<='Z')c=1;
    if(a&&b&&c&&i>=5)puts("Correct");
    else puts("Too weak");
    return 0;
}
