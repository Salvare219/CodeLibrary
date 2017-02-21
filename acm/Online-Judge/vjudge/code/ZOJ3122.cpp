#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


const int N = 16;
const int MAXN = N*N*N + 10;
const int MAXM = N*N*4 + 10;
const int maxnode = MAXN*4 + MAXM + 10;
struct DLX_Repeat
{
    int D[maxnode],U[maxnode],L[maxnode],R[maxnode],COL[maxnode],ROW[maxnode];
    int CNT,BEG[MAXN],END[MAXN],USE[MAXN],_USE[MAXN];
    int SUM[MAXM];
    bool has;
    int step;
    void init(int n)
    {
        memset(BEG,0xff,sizeof(BEG));
        for(int i=1;i<=n;i++)
            SUM[L[i+1]=R[i-1]=D[i]=U[i]=i]=0;
        L[L[1]=R[n]=0]=n;CNT=n+1;
        has=step=0;
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
            has=1;step=n;
            for(int i=0;i<n;i++)
                USE[i]=_USE[i];
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
char maz[20][20];
int ans[4100];
int main()
{
    int f=0;
    while(~scanf("%s",maz[0]))
    {
        if(f)putchar(10);
        f=1;
        for(int i=1;i<16;i++)
            scanf("%s",maz[i]);
        g.init(1024);
        int cnt=1;
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
                for(int k=1;k<=16;k++)
                    if(maz[i][j]=='-'||maz[i][j]==k+'A'-1)
                    {
                        g.insert(cnt,i*16+k);
                        g.insert(cnt,256+j*16+k);
                        g.insert(cnt,512+(i/4*4+j/4)*16+k);
                        g.insert(cnt,768+i*16+j+1);
                        ans[cnt++]=i*10000+j*100+k;
                    }
        g.DLX_Dfs(0);
        for(int i=0;i<g.step;i++)
        {
            int f=ans[g.USE[i]];
            int x=f/10000,y=f/100%100,z=f%100;
            maz[x][y]=z+'A'-1;
        }
        for(int i=0;i<16;i++)
            printf("%s\n",maz[i]);
    }
    return 0;
}
