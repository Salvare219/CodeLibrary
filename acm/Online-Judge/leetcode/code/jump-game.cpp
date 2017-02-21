bool cp[3050][3050];
int dp[3050];
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        memset(cp,0,sizeof(cp));
        for(int i=0;i<n;i++)
            for(int j=0;i-j>=0&&i+j<n;j++)
                if(s[i-j]!=s[i+j])
                    break;
                else
                    cp[i-j][i+j]=1;
        for(int i=0;i<n-1;i++)
            for(int j=1;i-j+1>=0&&i+j<n;j++)
                if(s[i-j+1]!=s[i+j])
                    break;
                else
                    cp[i-j+1][i+j]=1;
        for(int i=1;i<=n;i++)
            dp[i]=100000;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                if(cp[j][i-1])
                    dp[i]=min(dp[i],dp[j]+1);
        return dp[n]-1;
    }
};