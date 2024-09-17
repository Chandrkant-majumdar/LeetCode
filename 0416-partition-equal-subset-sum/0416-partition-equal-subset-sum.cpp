class Solution {
public:
    bool f(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(i==0){
            return nums[i]==sum;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool tk=(sum>=nums[i])?f(i-1,sum-nums[i],nums,dp):false;
        bool nt=f(i-1,sum,nums,dp);

        return dp[i][sum]=(tk||nt);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto x:nums){
            sum+=x;
        }
         if(sum%2) return false;
        sum/=2;

       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
         
        return f(n-1,sum,nums,dp);

    }

};