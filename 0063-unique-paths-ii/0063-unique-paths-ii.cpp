class Solution {
public:
     
     int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& g){
         int n=g.size(),m=g[0].size();
        if(i>=n || j>=m || g[i][j]==1) return 0; 
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=f(i+1,j,dp,g);
        int right=f(i,j+1,dp,g);

        return dp[i][j]=down+right;

     }
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        //  if(n==1 && m==1) return 1;
        // if(n==1) return 0;
       
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,dp,g);
    }
    int uniquePathsWithObstacles1(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        //  if(n==1 && m==1) return 1;
        // if(n==1) return 0;
       
        vector<vector<int>>dp(n,vector<int>(m,0));
        // if(g[n-1][m-1]==1)
        // dp[n-1][m-1]=0;
        // else
        if(g[0][0]==1 || g[n-1][m-1]==1) return 0;
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(g[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==n-1 && j==m-1) continue;
                //  (i+1<n)
                // if(g[i][j]==1){
                //     dp[i][j]=0;
                //     continue;
                // }
                 int down= (i+1<n)?dp[i+1][j]:0;

                  int right= (j+1<m)?dp[i][j+1]:0;

                  dp[i][j]=down+right;
            }
        }
        return dp[0][0];
    }
};