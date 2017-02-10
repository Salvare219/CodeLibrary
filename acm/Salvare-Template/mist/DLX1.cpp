VER 2.3
//矩阵标号从1开始
//g.init(COL_SIZE);
//g.insert(x,y);
//g.DLX_DFS(0);

const int MAXN=1005;
const int MAXM=1005;
const int INF=0X3fffffff;
struct DLX_Exact
{
    int D[MAXN*MAXM],U[MAXN*MAXM],L[MAXN*MAXM],R[MAXN*MAXM],COL[MAXN*MAXM],ROW[MAXN*MAXM];
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
            has=1;
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




VER 1.0


//矩阵标号从1开始
//g.n=ROW_SIZE;
//g.m=COL_SIZE;
//g.init();
//g.insert(x,y);
//g.initDFS();
//g.DFS(0);


const int MaxN=402;
const int MaxM=402;
struct DLX
{
    int h,n,m,tot;
    int U[MaxN*MaxM],D[MaxN*MaxM],L[MaxN*MaxM],R[MaxN*MaxM],Row[MaxN*MaxM],Col[MaxN*MaxM];
    int S[MaxM],O[MaxN];
    bool hasans;
    void init()
    {
        hasans=h=0;
        tot=m+n;
        for(int i=0;i<=m;i++)
        {
            D[i]=U[i]=Col[i]=i;
            Row[i]=S[i]=0;
            L[i]=(i+m)%(m+1);
            R[i]=(i+1)%(m+1);
        }
        for(int i=1;i<=n;i++)
        {
            R[i+m]=L[i+m]=i+m;
            Row[i+m]=i;
            Col[i+m]=0;
        }
    }
    void insert(int x,int y)
    {
        tot++;
        Row[tot]=x;
        Col[tot]=y;
        S[y]++;
        int colPos,rowPos;
        colPos=y;
        do colPos=D[colPos];
        while(colPos!=y&&Row[colPos]<=x);
        colPos=U[colPos];
        if(Row[colPos]==x)return;
        D[tot]=D[U[tot]=colPos];
        U[D[tot]]=D[U[tot]]=tot;
        rowPos=x+m;
        do rowPos=R[rowPos];
        while(rowPos!=x+m&&Col[rowPos]<=y);
        rowPos=L[rowPos];
        if(Col[rowPos]==y)return;
        R[tot]=R[L[tot]=rowPos];
        L[R[tot]]=R[L[tot]]=tot;
    }
    void cover(int col)
    {
        L[R[col]]=L[col];
        R[L[col]]=R[col];
        for(int i=D[col];i!=col;i=D[i])
            for(int j=R[i];j!=i;j=R[j])
                if(Col[j]!=col)
                {
                    U[D[j]]=U[j];
                    D[U[j]]=D[j];
                    S[Col[j]]--;
                }
    }
    void resume(int col)
    {
        for(int i=U[col];i!=col;i=U[i])
            for(int j=L[i];j!=i;j=L[j])
                if(Col[j]!=col)
                {
                    S[Col[j]]++;
                    U[D[j]]=j;
                    D[U[j]]=j;
                }
        L[R[col]]=col;
        R[L[col]]=col;
    }
    void initDFS()
    {
        for(int i=1;i<=n;i++)
        {
            L[R[i+m]]=L[i+m];
            R[L[i+m]]=R[i+m];
        }
    }
    void print(int deep)
    {
        printf("%d",deep);
        for(int i=0;i<deep;i++)
            printf(" %d",O[i]);
        putchar(10);
    }
    void DFS(int deep)
    {
        if(R[0]==0)
        {
            hasans=true;
            print(deep);
            return;
        }
        int tc=R[0];
        for(int i=R[0];i!=0;i=R[i])
            if(S[i]<S[tc])tc=i;
        cover(tc);
        for(int i=D[tc];i!=tc&&!hasans;i=D[i])
        {
            int temp=O[deep];
            O[deep]=Row[i];
            for(int j=R[i];j!=i;j=R[j])
                cover(Col[j]);
            DFS(deep+1);
            for(int j=L[i];j!=i;j=L[j])
                resume(Col[j]);
            O[deep]=temp;
        }
        resume(tc);
    }
}g;


