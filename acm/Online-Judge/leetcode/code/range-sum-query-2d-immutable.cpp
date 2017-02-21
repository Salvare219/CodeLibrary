class NumMatrix {
public:
    vector<vector<int>>sum;
    int n,m;
    NumMatrix(vector<vector<int>> &mat) {
        n=mat.size();
        if(n==0)return;
        m=mat[0].size();
        sum=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]-sum[i][j]+mat[i][j];
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        if(n==0)return 0;
        return sum[r2+1][c2+1]-sum[r2+1][c1]-sum[r1][c2+1]+sum[r1][c1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);