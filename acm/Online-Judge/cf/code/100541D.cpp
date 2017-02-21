#include<bits/stdc++.h>
using namespace std;


const int mod=100;
int v[105];
long long f[105];
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        long long n,k;
        scanf("%I64d%I64d",&n,&k);

/*
        long long m=n;
        for(int i=1;i<=k;i++)
            m=m+m%mod;
        printf("***%I64d\n",m);*/

        memset(v,-1,sizeof(v));
        int st=n%mod,las,dep=0;
        long long sum=0;
        while(v[st]==-1)
        {
            v[st]=dep++;
            sum+=st;
            f[st]=sum;
            las=st;
            st=st*2%mod;
        }
        if(k<=dep)
        {
            long long sum2=n;
            for(int i=1;i<=k;i++)
            {
                sum2=sum2+sum2%mod;
            }
            printf("%I64d\n",sum2);
        }
        else
        {
            long long T=dep-v[st];
            long long tot=f[las]-f[st]+st;
            long long ti=(k-dep)/T;
            long long res=ti*T+dep;
            long long sum2=ti*tot;
            long long sum3=0;
            for(int i=res+1;i<=k;i++)
                sum3+=st,st=st*2%mod;
            printf("%I64d\n",sum+sum2+sum3+n);
        }
    }
    return 0;
}
