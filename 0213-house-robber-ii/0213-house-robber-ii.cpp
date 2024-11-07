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
        if(nums.size()==1) return nums[0];
        vector<int>a(nums.begin(),nums.end()-1);
        vector<int>b(nums.begin()+1,nums.end());
        vector<int>dp1(a.size(),-1),dp2(b.size(),-1);
        return max(f(0,a,dp1),f(0,b,dp2));
    }
    int rob(vector<int>& nums) {
       
        if(nums.size()==1) return nums[0];
        vector<int>a(nums.begin(),nums.end()-1);
        vector<int>b(nums.begin()+1,nums.end());
         int n1=a.size(),n2=b.size();
        vector<int>dp1(n1+1,0),dp2(n2+1,0);
         dp1[n1-1]=a[n1-1];dp2[n2-1]=b[n2-1];

        for(int i=n1-2;i>=0;i--){
             int tk=a[i]+dp1[i+2];
             int nt=dp1[i+1];
         dp1[i]=max(nt,tk);
        }
        for(int i=n2-2;i>=0;i--){
             int tk=b[i]+dp2[i+2];
             int nt=dp2[i+1];
         dp2[i]=max(nt,tk);
        }


        return max(dp1[0],dp2[0]);
    }
};