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


int a[200005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    long long fa=0,temp=0;
    int sh=1;
    for(int i=1;i<n;i++)
    {
        temp=fa-(long long)a[i]*(n-1-i)*sh;
        if(temp<k)
        {
            printf("%d\n",i+1);
        }
        else
        {
            fa+=(long long)a[i]*sh;
            sh++;
        }
    }
    return 0;
}
