#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


const int MAXN=64;
const int MAXM=64;
const int INF=0X3fffffff;
struct DLX_Repeat
{
    int D[MAXN*MAXM],U[MAXN*MAXM],L[MAXN*MAXM],R[MAXN*MAXM],COL[MAXN*MAXM],ROW[MAXN*MAXM];
    int CNT,BEG[MAXN*MAXM],END[MAXN*MAXM],ANS;
    int SUM[MAXM];
    bool vis[MAXM];
    void init(int n)
    {
        memset(BEG,0xff,sizeof(BEG));
        for(int i=1;i<=n;i++)
            SUM[L[i+1]=R[i-1]=D[i]=U[i]=i]=0;
        L[L[1]=R[n]=0]=n;CNT=n+1;
        ANS=n+1;
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
        for(int i=D[c];i!=c;i=D[i])
            L[R[i]]=L[i],R[L[i]]=R[i],SUM[COL[i]]--;
    }
    void DLX_Resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            L[R[i]]=R[L[i]]=i,SUM[COL[i]]++;
    }
    int Heuristics()
    {
        memset(vis,true,sizeof(vis));
        int c,i,j,cnt=0;
        for(c=R[0];c;c=R[c])
            if(vis[c])
                for(cnt++,vis[c]=0,i=D[c];i!=c;i=D[i])
                    for(j=R[i];j!=i;j=R[j])
                        vis[COL[j]]=0;
        return cnt;
    }
    bool DLX_Dfs(int n,int fin)
    {
        if(Heuristics()+n>fin)return 0;
        if(R[0]==0)
            return 1;
        int i,now=INF,c;
        for(i=R[0];i;i=R[i])
            if(now>SUM[i])
                now=SUM[c=i];
        for(i=D[c];i!=c;i=D[i])
        {
            DLX_Remove(i);
            for(int j=R[i];j!=i;j=R[j])
                DLX_Remove(j);
            if(DLX_Dfs(n+1,fin))return 1;
            for(int j=L[i];j!=i;j=L[j])
                DLX_Resume(j);
            DLX_Resume(i);
        }
        return 0;
    }
}g;
pair<long long,long long>po[100];
int n,k;
inline long long dis(int x,int y)
{
    return abs(po[x].first-po[y].first)+abs(po[x].second-po[y].second);
}
inline bool ok(long long mid)
{
    g.init(n);
    g.ANS=k+1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dis(i,j)<=mid)
                g.insert(i+1,j+1);
    return g.DLX_Dfs(0,k);
    //return g.ANS<=k;
}
long long le[64*64];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        long long x,y;
        int f=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&x,&y);
            po[i]=make_pair(x,y);
            for(int j=0;j<i;j++)
                le[f++]=dis(i,j);
        }
        if(k==n)
            printf("Case #%d: 0\n",ti++);
        else
        {
            sort(le,le+f);
            f=unique(le,le+f)-le;
            long long l=0,r=f-1,mid;
            while(r>l)
            {
                mid=r+l>>1;
                if(ok(le[mid]))r=mid;
                else l=mid+1;
            }
            printf("Case #%d: %I64d\n",ti++,le[r]);
        }
    }
    return 0;
}
