#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int a[100005],b[100005];
bool cmp(int aa,int bb)
{
    return aa>bb;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    sort(a,a+n,cmp);
    sort(b,b+m,cmp);
    int lim=min(n,m),i=0,j=0;
    bool flag=0;
    while(i<n && j<m)
    {
        if(a[i]>b[j])
        {
            flag=1;
            break;
        }
        else i++,j++;
    }
    if(i<n) flag=1;
    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}





























