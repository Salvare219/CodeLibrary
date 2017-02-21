#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
    freopen("garage.in","r",stdin);
    freopen("garage.out","w",stdout);
    int W,H,w,h;
    scanf("%d%d%d%d",&W,&H,&w,&h);
    int d=W/(2*w),s=H/(2*h);
    int rd=W%(2*w),rs=H%(2*h);
    int ans=d*s;
    if(rd>=w)ans+=s;
    if(rs>=h)ans+=d;
    if(rd>=w&&rs>=h)ans++;
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
