#include<cstdio>
#include<deque>
#include<queue>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define maxn 1100


int num[maxn];
int a[maxn][maxn],b[maxn][maxn];

int main()
{
    int N,M,K;
    while(~scanf("%d%d%d",&N,&M,&K)){
        if(N==0&&M==0&&K==0) break;
        int P;
        scanf("%d",&P);
        memset(num,0,sizeof(num));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int t1,t2;
        char tt[20],ttt[30];
        for(int i=1;i<=P;i++){
            scanf("%s%d%s%d",tt,&t1,ttt,&t2);
            if(tt[0]=='c'){
                a[t1][t2]=1;
            }
            else b[t1][t2]=1;
        }
        for(int i=1;i<=M;i++){
            for(int j=1;j<=K;j++){
                if(!b[i][j]) num[i]++;
            }
        }
        long long ans=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(!a[i][j]) ans+=num[j];
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}