vector<int>dp[100000];
class Solution {
public:
    vector<string>ans;
    string c;
    void dfs(string g,int s)
    {
        if(s==0)
            ans.push_back(c);
        else
        {
            int len=c.size();
            for(int i=0;i<dp[s].size();i++)
                c=" "+g.substr(dp[s][i],s-dp[s][i])+c,dfs(g,dp[s][i]),c=c.substr(s-dp[s][i]+1,len);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string>& word) {
        int n=s.size();
        for(int i=0;i<=n;i++)
            dp[i].clear();
        dp[0].push_back(-1);
        for(int i=0;i<n;i++)
            if(dp[i].size())
                for(auto x:word)
                {
                    int len=x.size();
                    if(i+len<=n&&s.substr(i,len)==x)
                        dp[i+len].push_back(i);
                }
        ans.clear();
        dfs(s,n);
        for(auto &x:ans)
            x.erase(0,1);
        return ans;
    }
};