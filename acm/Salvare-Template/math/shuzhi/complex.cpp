//sigma(j,a[i][j]*xj)+b[i]>=0  ans=max(sigma(i,c[i]*x[i]))
//所有其他形式的线性规划方程组都可以按照下列方式转化成标准形式:
//1.目标函数并非最大化:将所有 ci 取负.
//2.约束条件中存在大于:将约束两边取负.
//3.约束条件中存在等式:将其转化成两个不等式.
//4.有的变量没有非负约束:加入新变量 x' ,并用 x-x' 替换原来的变量 x

//实数单纯形  z=a[0][0]+max(sigma(j,a[0][j]*x[j]))
//            0<=a[i][0]+sigma(j,a[i][j]*x[j])
//            n 为变元个数, m 为约束个数
//标准型要求  b[i]>=0

const int N=100;
const int M=100;
const double INF=1e20;
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
struct simplex
{
    int pf[N+M],m,n;
    double a[M][N],c[N],z;
    double x[N+M];
    int next[N];

    void pivot(int x,int y)
    {
        int las=-1;
        swap(pf[x],pf[n+y]);
        a[y][x]=1.0/a[y][x];
        for(int i=0;i<=n;i++)
            if(sgn(a[y][i])&&i!=x)next[i]=las,las=i,a[y][i]*=-a[y][x];
        for(int i=0;i<=m;i++)
            if(i!=y)
            {
                for(int j=las;~j;j=next[j])
                    a[i][j]+=a[y][j]*a[i][x];
                a[i][x]*=a[y][x];
            }
    }
    bool opt()
    {
        int pc,tc,i;
        double mc;
        while(1)
        {
            for(tc=i=1;i<=n;i++)
                if(sgn(a[0][i]-a[0][tc])>0)tc=i;
            if(sgn(a[0][tc])<=0)return z=a[0][0],1;
            pc=-1;mc=INF;
            for(i=1;i<=m;i++)
                if(sgn(a[i][tc])<0&&sgn(mc+a[i][0]/a[i][tc])>0)
                    mc=-a[pc=i][0]/a[i][tc];
            if(pc==-1)return 0;
            pivot(tc,pc);
        }
    }
    void pri()
    {
        for(int i=0;i<=m;i++,putchar(10))
            for(int j=0;j<=n;j++)
                printf("%f ",a[i][j]);
        putchar(10);
    }
    bool init()
    {
        double mc=1.0;
        int tc;
        for(int i=1;i<=n+m;i++)pf[i]=i;
        for(int i=1;i<=m;i++)
            if(sgn(mc-a[i][0])>0)mc=a[tc=i][0];
        if(sgn(mc)<0)
        {
            for(int i=1;i<=n;i++)c[i]=a[0][i],a[0][i]=0;
            a[0][++n]=-1;pf[n+m]=n+m;
            for(int i=1;i<=m;i++)a[i][n]=1;
            pivot(n,tc);opt();
            if(sgn(z)<0)return 0;
            for(int i=1;i<=n+m;i++)
                if(pf[i]==n)
                    if(i>n)pivot(1,i-n),tc=1;
                    else tc=i;
            for(int i=0;i<=m;i++)a[i][tc]=0;
            for(int i=1;i<=n;i++)if(pf[i]<n)a[0][i]+=c[pf[i]];
            for(int i=n+1;i<=m+n;i++)
                if(pf[i]<n)
                    for(int j=0;j<=n;j++)a[0][j]+=c[pf[i]]*a[i-n][j];
        }
        return 1;
    }
    int solv()
    {
        if(!init())return -1;     //无解
        if(!opt())return 0;       //无限大
        for(int i=1;i<=n;i++)
            x[pf[i]]=0;
        for(int i=n+1;i<=n+m;i++)
            x[pf[i]]=a[i-n][0];
        return 1;                 //有解
    }
}g;

