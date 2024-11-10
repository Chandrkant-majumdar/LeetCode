class Solution {
public:
    int f(int day ,int buy,vector<int>& p,vector<vector<int>>&dp,int fee){

        if(day==p.size()) return 0;
          if(dp[day][buy]!=-1) return dp[day][buy]; 
        if(buy){
            return dp[day][buy]=max(-p[day]+f(day+1,!buy,p,dp,fee),f(day+1,buy,p,dp,fee));
        }

        return dp[day][buy]=max(-fee+p[day]+f(day+1,!buy,p,dp,fee),f(day+1,buy,p,dp,fee));
     }
    int maxProfit(vector<int>& p,int fee) {
         int n=p.size();
        // int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans= f(0,1,p,dp,fee);
        return ans==-1e9?0:ans;
    }
};