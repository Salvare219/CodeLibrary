#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int x,a=m,b=k,con=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            if(a==0)con++,a++;
            a--;
        }
        else
        {
            if(b==0&&a==0) con++,a++;
            if(b) b--;
            else a--;
        }
    }
    printf("%d\n",con);
    return 0;
}
