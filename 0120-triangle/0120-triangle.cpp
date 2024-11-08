class Solution {
public:
   int f(int i,int j,vector<vector<int>>& t,vector<vector<int>>&dp){
    int n=t.size();
     int m=t[i].size();
    if(i>=n || j>=m) return 1e9;

    if(i==n-1){
        return t[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int down=t[i][j]+f(i+1,j,t,dp);
    int dig=t[i][j]+f(i+1,j+1,t,dp);
    return dp[i][j]=min(down,dig);
   }
    int minimumTotal(vector<vector<int>>& t) {
         int n=t.size();
     int m=t[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(0,0,t,dp);
    }
};