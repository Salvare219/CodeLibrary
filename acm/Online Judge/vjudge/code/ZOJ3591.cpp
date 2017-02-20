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


int a[100050];
int main()
{
//    freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N,S,W;
        scanf("%d%d%d",&N,&S,&W);
        int g = S;
        for (int i=0; i<N; i++) {
            a[i] = g;
            if( a[i] == 0 ) { a[i] = g = W; }
            if( g%2 == 0 ) { g = (g/2); }
            else           { g = (g/2) ^ W; }
        }
        int sum=0;
        for(int i=0;i<N;i++)
            sum^=a[i],a[i]=sum;
        sort(a,a+N);
        a[N]=0x7fffffff;
        int las=-1,num=0;
        long long ans=0;
        for(int i=0;i<=N;i++)
            if(las!=a[i])
            {
                if(las==0) ans+=num;
                ans+=(long long)num*(num-1)/2;
                las=a[i],num=1;
            }
            else num++;
        printf("%lld\n",(long long)(N+1)*N/2-ans);
    }
	return 0;
}
