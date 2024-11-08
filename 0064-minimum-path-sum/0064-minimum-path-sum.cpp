class Solution {
public: 
    int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& g){
        
        int n=g.size();
        int m=g[0].size();
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1){
           return g[i][j];
        }
         if(dp[i][j]!=-1) return dp[i][j];
        int down=g[i][j]+f(i+1,j,dp,g);
        int right=g[i][j]+f(i,j+1,dp,g);

        return dp[i][j]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& g) {
         int n=g.size();
        int m=g[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,dp,g);
    }
};