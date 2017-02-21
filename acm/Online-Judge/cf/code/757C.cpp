#include<bits/stdc++.h>
using namespace std;


const int mod=1000000007;
vector<vector<long long> >st;
int sa[1000050];
int cnt[1000050];
int mp[1000050],mk;
long long fac[1000050];
int main()
{
    //freopen("2.txt","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    fac[0]=1;
    for(int i=1;i<=m;i++)
    {
        mp[i]=-1;
        fac[i]=fac[i-1]*i%mod;
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d",&x);
        int k=0;
        for(int j=0;j<x;j++)
        {
            scanf("%d",&y);
            sa[k++]=y;
            cnt[y]++;
        }
        sort(sa,sa+k);
        k=unique(sa,sa+k)-sa;
        for(int j=0;j<k;j++)
        {
            int z=sa[j];
            if(mp[z]==-1)
            {
                mp[z]=mk++;
                vector<long long>te;
                st.push_back(te);
            }
            st[mp[z]].push_back(cnt[z]*1000000ll+i);
            cnt[z]=0;
        }
    }
    sort(st.begin(),st.end());
    int f=st.size(),sz=1;
    long long ans=1;
    for(int i=1;i<f;i++)
        if(st[i]==st[i-1])
            sz++;
        else
        {
            ans=ans*fac[sz]%mod;
            sz=1;
        }
    ans=ans*fac[sz]%mod;
    ans=ans*fac[m-mk]%mod;
    printf("%d\n",(int)ans);
    return 0;
}
