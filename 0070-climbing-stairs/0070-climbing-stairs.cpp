class Solution {
public:
    int f(int i,vector<int>&dp){
        if(i==0) return 1;
        if(i<0) return 0;
     if(dp[i]!=-1) return dp[i];
        int tk=f(i-1,dp);
        int nt=f(i-2,dp);
        return dp[i]=(tk+nt);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};