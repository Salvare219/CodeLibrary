#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char a[100005],b[100005];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s%s",a,b);
    int ans=0,sum=0;
    for(int i=0;a[i];i++)
        if(a[i]!=b[i])sum+=(a[i]=='4'),ans++;
    sum=min(sum,ans-sum);ans-=sum*2;
    printf("%d\n",sum+ans);
    return 0;
}
