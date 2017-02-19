#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#include<complex>
typedef complex<double> cplx;
const double pi=acos(-1.0);
void FFT(cplx F[],int len,int f)
{
    int i,j,k;
    cplx x,y,w=1,wn;
    for(i=1,j=len>>1;i<len-1;i++)
    {
        if(i<j)swap(F[i],F[j]);
        k=len>>1;
        while(j>=k)j^=k,k>>=1;
        j|=k;
    }
    for(i=2;i<=len;i<<=1)
    {
        wn=cplx(cos(-f*2*pi/i),sin(-f*2*pi/i));
        for(j=0;j<len;j+=i,w=1)
            for(k=j;k<j+i/2;k++,w*=wn)
            {
                x=F[k];y=w*F[k+i/2];
                F[k]=x+y;F[k+i/2]=x-y;
            }
    }
    if(f==-1)
        for(i=0;i<len;i++)F[i]/=len;
}
cplx a[500000],b[500000];
void conv(long long ca[],int l1,long long cb[],int l2,long long c[],int &l)
{
    l=1;while(l<l1+l2)l<<=1;
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
long long num[100050],con[500000];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x=0,y;memset(con,0,sizeof(con));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d",num+i),con[num[i]]++,x=max(x,(int)num[i]);x++;
        conv(con,x,con,x,con,y);sort(num,num+n);
        for(int i=0;i<n;i++)con[num[i]+num[i]]--;
        for(int i=1;i<=y;i++)con[i]>>=1,con[i]=con[i-1]+con[i];
        long long ans=0,mu=1ll*n*(n-1)*(n-2)/6;
        for(int i=0;i<n;i++)
        {
            ans+=con[y]-con[num[i]];
            ans-=n-1;
            ans-=1ll*(n-i-1)*i;
            ans-=1ll*(n-i-1)*(n-i-2)/2;
        }
        printf("%.7f\n",1.0*ans/mu);
    }
    return 0;
}
