#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool c[50][50];
bool v[50];
int main()
{
//    freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        int con=2*n+p;
        for(int i=0;i<n&&con!=0;i++)
            for(int j=i+1;j<n&&con!=0;j++)
            {
                printf("%d %d\n",i+1,j+1);
                con--;
            }
    }
    return 0;
}
