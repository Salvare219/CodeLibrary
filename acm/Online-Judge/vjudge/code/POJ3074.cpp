#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


const int MAXN=750;
const int MAXM=750;
const int INF=0X3fffffff;
struct DLX_Repeat
{
    int D[MAXN*MAXM],U[MAXN*MAXM],L[MAXN*MAXM],R[MAXN*MAXM],COL[MAXN*MAXM],ROW[MAXN*MAXM];
    int CNT,BEG[MAXN],END[MAXN],ANS,USE[MAXN],_USE[MAXN];
    int SUM[MAXM];
    bool has;
    int step;
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
            has=1;step=n;
            for(int i=0;i<n;i++)
                USE[i]=_USE[i];
            return;
        }
        int i,now=INF,c;
        for(i=R[0];i;i=R[i])
            if(now>SUM[i])
                now=SUM[c=i];
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
char s[150];
char maz[15][15];
int ans[450];
int main()
{
    while(scanf("%s",s)&&s[0]!='e')
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                maz[i][j]=s[i*9+j];
        g.init(324);
        int cnt=1;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                    for(int k=1;k<=9;k++)
                        if(maz[i][j]=='.'||maz[i][j]==k+'0')
                        {
                            g.insert(cnt,i*9+k);
                            g.insert(cnt,81+j*9+k);
                            g.insert(cnt,162+(i/3*3+j/3)*9+k);
                            g.insert(cnt,243+i*9+j+1);
                            ans[cnt++]=i*100+j*10+k;
                        }
        g.DLX_Dfs(0);
        for(int i=0;i<g.step;i++)
        {
            int f=ans[g.USE[i]];
            int x=f/100,y=f/10%10,z=f%10;
            maz[x][y]=z+'0';
        }
        for(int i=0;i<81;i++)
            s[i]=maz[i/9][i%9];
        printf("%s\n",s);
    }
    return 0;
}
