#include <bits/stdc++.h>

using namespace std;

inline long long lowbit(long long a)
{
    return a&(-a);
}

long long update(long long tree[],long long a,long long b,long long n)
{
    while (a<=n)
    {
        tree[a]+=b;
        a+=lowbit(a);
    }
    return 0;
}

long long ask(long long tree[],long long a)
{
    long long resu=0;
    while (a>0)
    {
        resu+=tree[a];
        a-=lowbit(a);
    }
    return resu;
}

long long tree[2000100];

int main()
{
    long long n, a, b;
    int CAS=0;
    while (cin>>n>>a>>b)
    {
        CAS++;
        if (n==0)
            break;
        for (int i=1; i<=2*n; i++)
            tree[i] = 0;
        long long ans = 0;
        for (int i=n-1; i>=0; i--)
        {
            long long num = (a*i+b)%n+1;
            ans+=ask(tree, num-1);
            update(tree, num, 1, n);
        }
        cout<<"Case "<<CAS<<": "<<ans<<endl;
    }
    return 0;
}
