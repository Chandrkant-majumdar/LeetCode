class Solution {
public:
    int f(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& ma){
       int n=ma.size();
       int m=ma[0].size();
       if(i<0 || i>=n || j<0 || j>=m) return 1e9;

       if(i==n-1){
        return ma[i][j];
       }
       if(dp[i][j]!=-2) return dp[i][j];
        int down=ma[i][j]+f(i+1,j,dp,ma);
        int ld=ma[i][j]+f(i+1,j-1,dp,ma);
        int rd=ma[i][j]+f(i+1,j+1,dp,ma);
        // int down=g[i][j]+f(i+1,j,dp,ma);
        return dp[i][j]=min({down,ld,rd});
        
        
    }
    int minFallingPathSum(vector<vector<int>>& ma) {
        int n=ma.size();
       int m=ma[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-2));
        int ans=1e9;
        for(int i=0;i<m;i++){
            ans=min(ans,f(0,i,dp,ma));
        }
        return ans;
    }
};