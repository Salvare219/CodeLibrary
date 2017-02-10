double f(double x)
{
    return x*x;
}
const int MAXREPT=10;
const double eps=1e-5;
double y[MAXREPT];
double Romberg(double aa, double bb)
{
    int m,n;
    double h,x,s,q,ep,p;
    h=bb-aa;
    y[0]=h*(f(aa)+f(bb))/2.0;
    m=n=1;ep=eps+1.0;
    while ((ep > eps) && (m < MAXREPT))
    {
        p=0.0;
        for(int i=0;i<n;i++)
            x=aa+(i+0.5)*h,p+=f(x);
        p=(y[0]+h*p)/2.0;s=1.0;
        for(int k=1;k<=m;k++)
        {
            s*=4.0;
            q=(s*p-y[k-1])/(s-1.0);
            y[k-1]=p;p=q;
        }
        p=fabs(q-y[m-1]);
        y[m++]=q;n<<=1;h/=2.0;
    }
    return q;
}