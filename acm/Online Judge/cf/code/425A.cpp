#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[5000];
int b[5000],c[5000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,z;scanf("%d%d",&n,&z);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int tot=-0x3fffffff;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            int ta=0,tb=0,sum=0;
            for(int k=0;k<n;k++)
                if(k>=i&&k<=j)b[ta++]=a[k],sum+=a[k];
                else c[tb++]=a[k];
            sort(b,b+ta);sort(c,c+tb);
            int p1=0,p2=tb-1;
            for(int k=0;k<z;k++)
                if(p2>=0&&p1<ta&&b[p1]<c[p2])
                {
                    sum+=c[p2--]-b[p1++];
                }
            tot=max(tot,sum);
        }
    printf("%d\n",tot);
    return 0;
}
