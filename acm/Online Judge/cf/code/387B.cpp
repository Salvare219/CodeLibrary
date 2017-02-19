#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[100000],b[100000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    sort(b,b+m);
    int p=0,ans=0;
    for(int i=0;i<n;i++)
    {
        while(p<m&&b[p]<a[i])p++;
        if(p>=m)ans++;p++;
    }
    printf("%d\n",ans);
	return 0;
}

