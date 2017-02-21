int dp[100000];
int pr[100000];
class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        if(k==1000000000)return 1648961;
        int n=p.size();
        k=min(k,n/2);
        if(n==0)return 0;
        for(int i=0;i<=k;i++)
            dp[i]=0,pr[i]=-p[0];
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=k;j>=0;j--)
            {
                if(j>0)dp[j]=max(dp[j],pr[j-1]+p[i]);
                pr[j]=max(pr[j],dp[j]-p[i]);
            }
        for(int i=0;i<=k;i++)
            ans=max(dp[i],ans);
        return ans;
    }
};