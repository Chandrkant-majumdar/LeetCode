class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        
        int n=nums.size();
         if(i>=n) return 0;
        if(i==n-1) return nums[i];
         if(dp[i]!=-1) return dp[i];
        int nt=f(i+1,nums,dp);
       int tk=0;
            if(i+2<=n)
         tk=nums[i]+f(i+2,nums,dp);
         

        return dp[i]=max(nt,tk);

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        if(nums.size()==1) return nums[0];
        return max(f(0,nums,dp),f(1,nums,dp));
    }
};