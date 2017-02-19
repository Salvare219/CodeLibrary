#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


bool a[24],b[24];
int main()
{
    for(int i=0;i<20;i++)
        scanf("%d",a+i),b[i]=a[i];
    int ans=1,ans2=0;
    b[0]=!a[0];b[1]=!a[1];
    for(int i=0;i<20;i++)
        if(b[i]) ans++,b[i]=0,b[i+1]^=1,b[i+2]^=1;
    for(int i=0;i<20;i++)
        if(a[i]) ans2++,a[i]=0,a[i+1]^=1,a[i+2]^=1;
    printf("%d\n",min(ans,ans2));
    return 0;
}
