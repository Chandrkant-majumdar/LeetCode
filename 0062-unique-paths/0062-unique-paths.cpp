class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>&dp){

        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int d=f(i+1,j,n,m,dp);
        int r=f(i,j+1,n,m,dp);
        return dp[i][j]=d+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,dp);
    }
};