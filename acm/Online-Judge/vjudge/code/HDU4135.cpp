#include <cstdio>
int f[30],cnt;
typedef long long LL;
LL a,b;
int n;
LL tol,ans;
void dfs(int s,LL mul,int t)
{
    if(s==cnt){
        if(t) ans=ans+tol/mul;
        else ans=ans-tol/mul;
        return;
    }
    dfs(s+1,mul,t);
    dfs(s+1,mul*f[s],1-t);
}
LL cal(LL x)
{
    if(x==0) return 0;
    tol=x;
    ans=0;
    dfs(0,1,1);
    return ans;
}
int main()
{
  // freopen("1.in","r",stdin);
    int T,ca=0;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%d",&a,&b,&n);
        if(n==1) { printf("Case #%d: %I64d\n",++ca,b-a+1);continue;}
        cnt=0;
        for(int j=2;j*j<=n;j++){
            if(n%j==0){
                f[cnt++]=j;
                while(n%j==0) n/=j;
            }
        }
        if(n>1) f[cnt++]=n;

       // for(int i=0;i<cnt;i++) printf("%d\n",f[i]);
        printf("Case #%d: %I64d\n",++ca,cal(b)-cal(a-1));
    }
}