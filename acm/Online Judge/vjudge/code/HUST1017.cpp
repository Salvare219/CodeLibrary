#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


const int MAXN=1005;
const int MAXM=1005;
const int INF=0X3fffffff;
struct DLX_Exact
{
    int D[MAXN*MAXM],U[MAXN*MAXM],L[MAXN*MAXM],R[MAXN*MAXM],COL[MAXN*MAXM],ROW[MAXN*MAXM];
    int CNT,BEG[MAXN],END[MAXN],ANS,USE[MAXM],_USE[MAXM];
    int SUM[MAXM];
    bool vis[MAXM],has;
    void init(int n)
    {
        memset(BEG,0xff,sizeof(BEG));
        for(int i=1;i<=n;i++)
            SUM[L[i+1]=R[i-1]=D[i]=U[i]=i]=0;
        L[L[1]=R[n]=0]=n;CNT=n+1;
        has=0;
    }
    void insert(int r,int c)
    {
        D[CNT]=D[c];U[CNT]=c;U[D[c]]=CNT;D[c]=CNT;
        COL[CNT]=c;ROW[CNT]=r;SUM[c]++;
        if(BEG[r]==-1)BEG[r]=END[r]=CNT;
        R[END[r]]=CNT;L[CNT]=END[r];R[CNT]=BEG[r];
        L[BEG[r]]=CNT;END[r]=CNT++;
    }
    void DLX_Remove(int c)
    {
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for(int i=D[c];i!=c;i=D[i])
            for(int j=R[i];j!=i;j=R[j])
                U[D[j]]=U[j],D[U[j]]=D[j],SUM[COL[j]]--;
    }
    void DLX_Resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            for(int j=L[i];j!=i;j=L[j])
                U[D[j]]=j,D[U[j]]=j,SUM[COL[j]]++;
        L[R[c]]=c;
        R[L[c]]=c;
    }
    void DLX_Dfs(int n)
    {
        if(R[0]==0)
        {
            has=1;
            for(int i=0;i<n;i++)
                USE[i]=_USE[i];
            printf("%d",n);
            for(int i=0;i<n;i++)
                printf(" %d",USE[i]);putchar(10);
            return;
        }
        int i,c=R[0];
        for(i=R[0];i;i=R[i])
            if(SUM[c]>SUM[i])c=i;
        DLX_Remove(c);
        for(i=D[c];i!=c&&!has;i=D[i])
        {
            for(int j=R[i];j!=i;j=R[j])
                DLX_Remove(COL[j]);
            _USE[n]=ROW[i];
            DLX_Dfs(n+1);
            for(int j=L[i];j!=i;j=L[j])
                DLX_Resume(COL[j]);
        }
        DLX_Resume(c);
    }
}g;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        g.init(m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<x;j++)
                scanf("%d",&y),g.insert(i,y);
        }
        g.DLX_Dfs(0);
        if(g.has);
        else puts("NO");
    }
    return 0;
}