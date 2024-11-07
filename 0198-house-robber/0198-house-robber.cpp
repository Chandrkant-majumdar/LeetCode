class Solution {
public:
    int f(int i,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(i>=n) return 0;
        if(i==n-1) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int tk=nums[i]+f(i+2,nums,dp);
        int nt=f(i+1,nums,dp);
        return dp[i]=max(nt,tk);
    }
    int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
             int tk=nums[i]+f(i+2,nums,dp);
        int nt=f(i+1,nums,dp);
         dp[i]=max(nt,tk);
        }

        return dp[0];
    }
};