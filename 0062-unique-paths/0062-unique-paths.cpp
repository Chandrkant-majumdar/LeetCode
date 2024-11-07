class Solution {
public:
   int f(int i,int j,int n, int m,vector<vector<int>>&dp){
      if(i>=n || j>=m) return 0;
      if(i==n-1 && j==m-1) return 1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      int down=f(i+1,j,n,m,dp);
      int right=f(i,j+1,n,m,dp);

      return dp[i][j]=down+right;


   }
    int uniquePaths1(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                //   if(dp[i][j]!=-1) return dp[i][j];
                if(i==m-1 && j==n-1) continue;
      int down=(i+1<m)?dp[i+1][j]:0;
      int right=(j+1<n)?dp[i][j+1]:0;

   dp[i][j]=down+right;
            }
        }

        return dp[0][0];
    }
};