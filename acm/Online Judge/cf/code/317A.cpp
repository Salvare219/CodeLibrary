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


int main()
{
//	freopen("1.txt","r",stdin);
	long long x,y,m;
	scanf("%I64d%I64d%I64d",&x,&y,&m);
	if(x>y) swap(x,y);
	if(y>=m) printf("0\n");
	else
    {
        if(x<=0 && y<=0) printf("-1\n");
        else
        {
            long long ans=0,temp=0;
            if(x<0)
            {
                ans=(-x)/y;temp=(-x)%y;
                ans++;x=-temp+y;
            }
            while(y<m)
            {
                ans++;
                temp=y;
                y=x+y;x=temp;
            }
            printf("%I64d\n",ans);
        }
    }
	return 0;
}
