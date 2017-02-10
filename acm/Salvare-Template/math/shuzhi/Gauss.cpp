//一般方程高斯消元  好板
const int MAXN=50;

int a[MAXN][MAXN];//增广矩阵
int x[MAXN];//解集
bool free_x[MAXN];//标记是否是不确定的变元 1 表示不确定
inline int lcm(int n,int m)
{
    int a=n,b=m,c=n%m;
    while(c)a=b,b=c,c=a%b;
    return n/b*m;
}
int Gauss(int equ,int var)
{
    int i,j,k,max_r,col=0;
    int temp,LCM,ta,tb;
    int free_x_num,free_index;
    for(i=0;i<=var;i++)
        x[i]=0,free_x[i]=1;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        if(max_r!=k) for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
            if(a[i][col]!=0)
            {
                LCM=lcm(abs(a[i][col]),abs(a[k][col]));
                ta=LCM/abs(a[i][col]);tb=LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0) tb=-tb;
                for(j=col;j<var+1;j++)
                    a[i][j]=a[i][j]*ta-a[k][j]*tb;
            }
    }
    for(i=k;i<equ;i++)
        if(a[i][col]!=0) return -1;
    if(k<var)
    {
        for(i=k-1;i>=0;i--)
        {
            free_x_num=0;
            for(j=0;j<var;j++)
                if (a[i][j]!=0 && free_x[j]) free_x_num++,free_index=j;
            if(free_x_num>1) continue;
            temp=a[i][var];
            for(j=0;j<var;j++)
                if (a[i][j]!=0 && j!=free_index) temp-=a[i][j]*x[j];
            x[free_index]=temp/a[i][free_index];
            free_x[free_index]=0;
        }
        return var-k;  //自由变元个数
    }
    else  //唯一解
    {
        for(i=var-1;i>-1;i--)
        {
            temp=a[i][var];
            for(j=i+1;j<var;j++)
                if(a[i][j]!=0) temp-=a[i][j]*x[j];
            if(temp%a[i][i]!=0) return -2; //浮点解
            x[i]=temp/a[i][i];
        }
        return 0;
    }
}