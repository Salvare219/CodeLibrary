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


int fa[200000];
map<int,int> p;
int main()
{
	int n,m,x,y,temp;
    scanf("%d%d",&n,&m);
    p[0]=1;
    int sum=0;
	for(int i=0;i<n;i++)
	{
        scanf("%d%d",&x,&y);
        sum+=x*y;
        p[sum+1]=i+2;
	}
	for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        printf("%d\n",(--p.upper_bound(x))->second);
    }
    return 0;
}
