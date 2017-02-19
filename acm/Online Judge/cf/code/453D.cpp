#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define mo 1000000007
#define inf 1000000000

typedef long long ll;



int m;
long long t, p, q;
int fox[21];
void init() {
    fox[0] = 1;
    for(int i = 1; i <= 20; i++) {
        fox[i] = fox[i - 1] << 1;
    }
}

ll mul(ll a, ll b) {
    if(a > 0 && b > 0 && a * b < 0) while(1);
    ll c = ((ll)(a * b - (ll)((long double)a * b / p) * p) % p + p) % p;
    if(c < 0) c += p;
    return c;
}

long long cal(long long c) {
    c = c % p;
    if(c < 0) return c + p;
    else return c;
}

void tf(long long a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    tf(a,l,mid); tf(a,mid,r);
    for(int i=0;i<len;i++)
    {
        long long x1=a[l+i];
        long long x2=a[mid+i];
        a[l+i] = cal(x1-x2);
        a[mid+i] = cal(x1+x2);
    }
}

void utf(long long a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    for(int i=0;i<len;i++)
    {
        long long x1=a[l+i];
        long long x2=a[mid+i];
        a[l + i] = cal(x1 + x2);
        a[mid + i] = cal(x2 - x1);
    }
    utf(a,l,mid);utf(a,mid,r);
}

long long e[2000001];
long long b[2000001];
long long c[2000001];

long long power_mod(long long a, long long b) {
    long long res = 1;
    while(b) {
        if(b & 1) {
            res = mul(res, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return res;
}

int main()
{

    //freopen("1.txt","r",stdin);
    init();
    scanf("%d%I64d%I64d", &m, &t, &p);

    p *= fox[m];


    for(int i = 0; i < fox[m]; i++) {
        scanf("%I64d", &e[i]);
    }

    for(int i = 0; i <= m; i++) {
        scanf("%I64d", &b[i]);
    }

    for(int i = 0; i < fox[m]; i++) {
        int a = __builtin_popcount(i);
        c[i] = b[a];
    }

    tf(e, 0, fox[m]);
    tf(c, 0, fox[m]);

    for(int i = 0; i <= m; i++) {
        b[i] = power_mod(c[(1 << i) - 1], t);
    }

    for(int i = 0; i < fox[m]; i++) {
        c[i] = b[__builtin_popcount(i)];
    }

    for(int i = 0; i < fox[m]; i++) {
        e[i] = mul(e[i], c[i]);
    }

    utf(e, 0, fox[m]);

    for(int i = 0; i < fox[m]; i++) {
        printf("%I64d\n", e[i] / fox[m]);
    }

    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
//const ll mod=1000000007;

const int N=(1<<20)+10;
typedef long long ll;
int m,n;
ll t,p,a[N],b[N],e[30];

ll mul(ll a,ll b) {return ((a*b-ll((long double)a*b/p)*p)%p+p)%p;}

ll powmod(ll a,ll b) { ll res=1; for(;b;b>>=1) { if(b&1) res=mul(res,a); a=mul(a,a);} return res;}
void dft(ll *a,int l,int r) {
    if (l==r) return;
    int md=(l+r)>>1,len=(r-l+1)>>1;
    dft(a,l,md);dft(a,md+1,r);
    rep(i,0,len) {
        ll x1=a[l+i],x2=a[l+len+i];
        a[l+i]=x1-x2;
        if (a[l+i]<0) a[l+i]+=p;
        a[l+len+i]=x1+x2;
        if (a[l+len+i]>=p) a[l+len+i]-=p;
    }
}
void idft(ll *a,int l,int r) {
    if (l==r) return;
    int md=(l+r)>>1,len=(r-l+1)>>1;
    rep(i,0,len) {
        ll x1=a[l+i],x2=a[l+len+i];
        a[l+i]=x1+x2;
        if (a[l+i]>=p) a[l+i]-=p;
        a[l+len+i]=x2-x1;
        if (a[l+len+i]<0) a[l+len+i]+=p;
    }
    idft(a,l,md);idft(a,md+1,r);
}

int main() {
    freopen("1.txt", "r", stdin);
    scanf("%d%I64d%I64d",&m,&t,&p);
    n=1<<m; p*=n;
    rep(i,0,n) scanf("%I64d",a+i),a[i]%=p;
    rep(i,0,m+1) scanf("%I64d",e+i),e[i]%=p;
    rep(i,0,n) b[i]=e[__builtin_popcount(i)];
    for(int i = 0; i < n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    dft(a,0,n-1);
    dft(b,0,n-1);
    for(int i = 0; i < n; i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    rep(i,0,m+1) e[i]=powmod(b[(1<<i)-1],t);
    rep(i,0,n) b[i]=e[__builtin_popcount(i)];
    rep(i,0,n) a[i]=mul(a[i],b[i]);
    idft(a,0,n-1);
    rep(i,0,n) printf("%I64d\n",a[i]>>m);
}
*/
