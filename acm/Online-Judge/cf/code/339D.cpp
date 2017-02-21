#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int num[20][150000];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int how=1<<n;
    for(int i=0;i<how;i++)
        scanf("%d",&num[0][i]);
    for(int i=1;i<=n;i++)
    {
        int fa=how/(1<<(i-1));
        for(int j=0;j<fa;j+=2)
            if(i%2) num[i][j/2]=num[i-1][j]|num[i-1][j+1];
            else num[i][j/2]=num[i-1][j]^num[i-1][j+1];
    }
    int q,s;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&q,&s);
        q--;
        num[0][q]=s;
        if(q%2) q--;
        for(int i=1;i<=n;i++)
        {
            s=q/2;
            if(i%2) num[i][s]=num[i-1][q]|num[i-1][q+1];
            else num[i][s]=num[i-1][q]^num[i-1][q+1];
            q/=2;
            if(q%2) q--;
        }
        printf("%d\n",num[n][0]);
    }
	return 0;
}
