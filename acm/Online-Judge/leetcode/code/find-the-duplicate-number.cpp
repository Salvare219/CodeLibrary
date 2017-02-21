bool v[50][50][50][50];
bool dp[50][50][50][50];
class Solution {
public:
    string x,y;
    bool dfs(int l1,int r1,int l2,int r2)
    {
        if(r1==l1)return x[l1]==y[l2];
        if(v[l1][r1][l2][r2])return dp[l1][r1][l2][r2];
        v[l1][r1][l2][r2]=1;
        int n=r1-l1+1;
        for(int i=0;i<n-1;i++)
        {
            if(dfs(l1,l1+i,l2,l2+i)&&dfs(l1+i+1,r1,l2+i+1,r2))return dp[l1][r1][l2][r2]=1;
            if(dfs(l1,l1+i,r2-i,r2)&&dfs(l1+i+1,r1,l2,r2-i-1))return dp[l1][r1][l2][r2]=1;
        }
        return dp[l1][r1][l2][r2]=0;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        x=s1;y=s2;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    for(int l=0;l<n;l++)
                        v[i][j][k][l]=0;
        return dfs(0,n-1,0,n-1);
    }
};