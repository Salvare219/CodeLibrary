#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int x,y,x1,y1,s;
        scanf("%d%d%d%d",&x,&y,&x1,&y1);
        s=max(max(x,x1),max(y,y1));
        long long c1=x-x1,c2=y-y1;
        if(c1*c2>0) printf("Case %d: %d %d %d %d\n",ti++,s,0,s-abs((int)c2),abs((int)c1));
        else printf("Case %d: %d %d %d %d\n",ti++,0,0,abs((int)c2),abs((int)c1));
    }
	return 0;
}
