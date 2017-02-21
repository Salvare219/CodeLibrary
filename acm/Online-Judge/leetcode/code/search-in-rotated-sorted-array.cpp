long long dp[2][100000];
class Solution {
public:

    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        for(int i=1;i<=n;i++)
            dp[0][i]=0;
        dp[0][0]=1;
        int f=0;
        for(int i=1;i<=m;i++)
        {
            long long sum=dp[f][dp[f^1][0]=0];
            for(int j=1;j<=n;sum+=dp[f][j++])
                if(s[j-1]==t[i-1])dp[f^1][j]=sum;
                else dp[f^1][j]=0;
            f^=1;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
            ans+=dp[f][i];
        return ans;
    }
};