class Solution {
public:
    int f(int i,vector<int>&dp){

        if(i==0) return 1;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int tk1=f(i-1,dp);
        int  tk2=f(i-2,dp);
        return dp[i]=tk1+tk2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            int tk1=dp[i-1];
            int  tk2=(i-2>=0)?dp[i-2]:0;
            dp[i]=tk1+tk2;
        }

        return dp[n];
    }
};