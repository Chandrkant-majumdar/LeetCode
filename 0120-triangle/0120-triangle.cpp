class Solution {
public:
    int f(int i,int j,vector<vector<int>>& ma, vector<vector<int>>&dp){
        int n=ma.size();

        // int m=ma[0]
        if(i<0 || j<0 || j>i ){
            return 1e9;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0 && j==0) return ma[i][j];
        int up=ma[i][j]+f(i-1,j,ma,dp);
        int down=ma[i][j]+f(i-1,j-1,ma,dp);
        // int dig=ma[i][j]+f(i-1,j+1,ma);

        return dp[i][j]=min(up,down);
    }
    int minimumTotal(vector<vector<int>>& ma) {
       int n=ma.size();
       int m=ma[n-1].size();
        int ans=INT_MAX;
       
        for(int i=0;i<m;i++){
             vector<vector<int>>dp(n,vector<int>(m,-1));
            ans=min(ans,f(n-1,i,ma,dp));
        }
        return ans;
        
    }
};