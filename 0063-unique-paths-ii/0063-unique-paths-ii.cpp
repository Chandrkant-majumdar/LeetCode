class Solution {
public:
   int f(int i,int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>& o){

        if(i>=n || j>=m || o[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int d=f(i+1,j,n,m,dp,o);
        int r=f(i,j+1,n,m,dp,o);
        return dp[i][j]=d+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size();
        int m=o[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,n,m,dp,o);
    }
};