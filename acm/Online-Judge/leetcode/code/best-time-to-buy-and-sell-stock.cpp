int dp[100000];
int pr[100000];
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int k=1;
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