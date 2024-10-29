class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> dp(n,vector<int>(m,1));
        for(int i=0; i<n; i++)
        dp[i][m-1]=1;

        for(int j=m-2; j>=0; j--)
        {
            for(int i=0; i<n; i++)
            {
                if(i+1<n && j+1<m && grid[i+1][j+1]>grid[i][j])
                dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                if(i-1>=0 && j+1<m && grid[i-1][j+1]>grid[i][j])
                dp[i][j]=max(dp[i][j],1+dp[i-1][j+1]);
                if(j+1<m && grid[i][j+1]>grid[i][j])
                dp[i][j]=max(dp[i][j],1+dp[i][j+1]);
            }
        }

        int num=0;
        for(int i=0; i<n; i++)
        {
            num=max(num,dp[i][0]);
        }
        return num-1;
    }
};