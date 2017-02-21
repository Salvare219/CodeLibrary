#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct cplx
{
    double x,y;
    cplx(){}
    cplx(double _x,double _y){x=_x;y=_y;}
    cplx operator+(const cplx&a)const{return cplx(x+a.x,y+a.y);}
    cplx operator-(const cplx&a)const{return cplx(x-a.x,y-a.y);}
    cplx operator*(const cplx&a)const{return cplx(x*a.x-y*a.y,x*a.y+y*a.x);}
};
const double pi=acos(-1.0);
void FFT(cplx F[],int len,int f)
{
    int i,j,k;
    cplx x,y,w=cplx(1,0),wn;
    for(i=1,j=len>>1;i<len-1;i++)
    {
        if(i<j)swap(F[i],F[j]);
        k=len>>1;
        while(j>=k)j^=k,k>>=1;
        j|=k;
    }
    for(i=1;i<len;i<<=1)
    {
        wn=cplx(cos(-f*pi/i),sin(-f*pi/i));
        for(j=0;j<len;j+=i<<1,w=cplx(1,0))
            for(k=j;k<j+i;k++,w=w*wn)
            {
                x=F[k];y=w*F[k+i];
                F[k]=x+y;F[k+i]=x-y;
            }
    }
    if(f==-1)
        for(i=0;i<len;i++)F[i].x/=len;
}
cplx a[500000],b[500000];
void conv(int ca[],int l1,int cb[],int l2,int c[],int &l)
{
    l=1;while(l<l1+l2)l<<=1;
    for(int i=0;i<l;i++)
    {
        a[i]=i<l1?cplx(ca[i],0):cplx(0,0);
        b[i]=i<l2?cplx(cb[i],0):cplx(0,0);
    }
    FFT(a,l,1);FFT(b,l,1);
    for(int i=0;i<l;i++)a[i]=a[i]*b[i];
    FFT(a,l,-1);
    for(int i=0;i<l;i++)c[i]=a[i].x+0.5;
}
char ca[70005],cb[70005];
int sa[70005],sb[70005];
int sc[130000];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",ca,cb);
        int l,l1=strlen(ca),l2=strlen(cb);
        for(int i=0;i<l1;i++)
            sa[i]=ca[l1-i-1]-'0';
        for(int i=0;i<l2;i++)
            sb[i]=cb[l2-i-1]-'0';
        conv(sa,l1,sb,l2,sc,l);
        for(int i=0;i<l;i++)
            sc[i+1]+=sc[i]/10,sc[i]%=10;
        int f=l-1;
        while(f!=-1&&sc[f--]==0);
        for(int i=f+1;i>-1;i--)
            putchar(sc[i]+'0');putchar(10);
    }
    return 0;
}
