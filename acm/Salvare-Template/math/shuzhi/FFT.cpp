//FFT
//注意数组范围  可以使用万进制来加速
Ver 1.0
#include<complex>
typedef complex<double> cplx;
const double pi=acos(-1.0);
void FFT(cplx F[],int len,int f)
{
    int i,j,k;
    cplx x,y,w=1,wn;
    for(i=1,j=0,k=0;i<=len;i++)
    {
        if(j<k) swap(F[j],F[k]);
        j^=i&-i;
        k^=len/(i&-i)>>1;
    }
    for(i=1;i<len;i<<=1)
    {
        wn=cplx(cos(-f*pi/i),sin(-f*pi/i));
        for(j=0;j<len;j+=i<<1,w=1)
            for(k=j;k<j+i;k++,w*=wn)
            {
                x=F[k];y=w*F[k+i];
                F[k]=x+y;F[k+i]=x-y;
            }
    }
    if(f==-1)
        for(i=0;i<len;i++)F[i]/=len;
}
cplx a[500000],b[500000];
void conv(int ca[],int l1,int cb[],int l2,int c[],int &l)
{
    l=1<<(32-__builtin_clz(l1+l2));
    for(int i=0;i<l;i++)
    {
        a[i]=i<l1?cplx(ca[i],0):cplx(0,0);
        b[i]=i<l2?cplx(cb[i],0):cplx(0,0);
    }
    FFT(a,l,1);FFT(b,l,1);
    for(int i=0;i<l;i++)a[i]*=b[i];
    FFT(a,l,-1);
    for(int i=0;i<l;i++)c[i]=a[i].real()+0.5;
}

