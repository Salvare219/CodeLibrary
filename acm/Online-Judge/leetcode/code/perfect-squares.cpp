int dp[10000],g;
class Solution {
public:
    Solution()
    {
        if(g==0)
        {
            g=1;
            dp[0]=0;
            for(int i=1;i<10001;i++)
            {
                int sum=100000;
                for(int j=1;j*j<=i;j++)
                    sum=min(dp[i-j*j]+1,sum);
                dp[i]=sum;
            }
        }
    }
    int numSquares(int n) {
        return dp[n];
    }
};