class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(i>=n) return 0;
        if(i==n-1) return nums[i];
        if(dp[i]!=-1) return dp[i];
        int nt=f(i+1,nums,dp);
        int tk=0;
        if(i+2<=n){
            tk=nums[i]+f(i+2,nums,dp);
        }
        return dp[i]=max(nt,tk);
    }
    int rob(vector<int>& nums) {
        // nums.push_back(nums[0]);
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>t1,t2;
        vector<int>dp1(n,-1),dp2(n,-1);
        for(int i=0;i<nums.size();i++){
                if(i!=0){
                    t1.push_back(nums[i]);
                }
                if(i!=n-1){
                    t2.push_back(nums[i]);
                }
        }
        return max(f(0,t1,dp1),f(0,t2,dp2));
    }
};