#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool v[1000005];
int a[1000005];
int fin[1000005];
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n=Int();
    for(int i=0;i<n;i++)
    {
        a[i]=Int();
        v[a[i]]=1;
    }
    sort(a,a+n);
    int sb=1000001,k=0,cnt=0;
    for(int i=0;i<n;i++)
        if(v[sb-a[i]]==0)
        {
            v[sb-a[i]]=1;
            fin[k++]=sb-a[i];
        }
        else cnt++;
    for(int i=1;i<sb&&cnt;i++)
        if(v[i]==0&&v[sb-i]==0)
        {
            fin[k++]=i;
            fin[k++]=sb-i;
            cnt-=2;
        }
    sort(fin,fin+k);
    printf("%d\n",k);
    for(int i=0;i<k;i++)
        printf("%d ",fin[i]);
    putchar(10);
    return 0;
}
