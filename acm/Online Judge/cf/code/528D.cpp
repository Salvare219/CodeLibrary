#include <bits/stdc++.h>
using namespace std;


#define MAXN 200011

int s, t, K;

char bx[MAXN], bt[MAXN];

char rec(int a) {
    if(a == 0) return 'A';
    else if(a == 1) return 'C';
    else if(a == 2) return 'T';
    else if(a == 3) return 'G';
}

bool canf[MAXN][4];

const int mod=211812353,g=3;
int _g[30],_ig[30];
long long invl;
int pow_mod(long long a,int b)
{
    long long c=1;
    while(b)
    {
        if(b&1)c=c*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return c;
}
void init()
{
    for(int i=0;i<30;i++)
    {
        _g[i]=pow_mod(g,(mod-1)/(1<<i));
        _ig[i]=pow_mod(_g[i],mod-2);
    }
}
void FNT(int F[],int len,int f)
{
    int i,j,k,cnt=1,x,y;
    long long w=1,wn;
    for(i=1,j=len>>1;i<len-1;i++)
    {
        if(i<j)swap(F[i],F[j]);
        k=len>>1;
        while(j>=k)j^=k,k>>=1;
        j|=k;
    }
    for(i=1;i<len;i<<=1)
    {
        wn=f?_g[cnt++]:_ig[cnt++];
        for(j=0;j<len;j+=i<<1,w=1)
            for(k=j;k<j+i;k++,w=w*wn%mod)
            {
                x=F[k];y=w*F[k+i]%mod;
                F[k]=x+y;F[k+i]=x-y;
                if(F[k]>=mod)F[k]-=mod;
                if(F[k+i]<0)F[k+i]+=mod;
            }
    }
    if(!f)
        for(i=0;i<len;i++)F[i]=F[i]*invl%mod;
}
int a[800000],b[800000];
void conv(int ca[],int l1,int cb[],int l2,int c[],int &l)
{
    l=1;while(l<l1+l2)l<<=1;
    init();invl=pow_mod(l,mod-2);
    for(int i=0;i<l;i++)
    {
        a[i]=i<l1?ca[i]:0;
        b[i]=i<l2?cb[i]:0;
    }
    FNT(a,l,1);FNT(b,l,1);
    for(int i=0;i<l;i++)a[i]=(long long)a[i]*b[i]%mod;
    FNT(a,l,0);
    for(int i=0;i<l;i++)c[i]=a[i];
}

int a1[800000], a2[800000], ans[800000], f_ans[800000];

int main()
{
    //freopen("pro.in","r",stdin);

    scanf("%d%d%d", &s, &t, &K);

    scanf("%s", bx);
    scanf("%s", bt);
    int len = strlen(bx);
    int m = strlen(bt);

    for(int i = 0; i < 4; i++) {
        char a = rec(i);
        int pr = 0;
        for(int j = 0; j < len; j++) {
            if(bx[j] == a) {
                int l = max(j - K, 0); int r = min(j + K, len - 1);
                l = max(pr, l);
                if(pr > r) continue;
                else {
                    for(int k = l; k <= r; k++) {
                        canf[k][i] = 1;
                    }
                    pr = r + 1;
                }
            }
        }
    }

    for(int i = 0; i < 4; i++) {
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        for(int j = 0; j < len; j++) {
            if(canf[j][i]) a1[j] = 1;
        }
        for(int j = 0; j < m; j++) {
            if(bt[j] == rec(i)) {
                a2[m - j - 1] = 1;
            }
        }
        int ll;
        conv(a1, len, a2, m, ans, ll);
        for(int j = 0; j < ll; j++) {
            f_ans[j] += ans[j];
        }
    }

    int ff = 0;
    for(int j = 0; j < len + m; j++) {
        if(f_ans[j] == m) ff++;
    }
    printf("%d\n", ff);

    return 0;
}
