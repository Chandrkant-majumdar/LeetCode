class Solution {
public:
    int f(int day ,int buy,vector<int>& p,vector<vector<int>>&dp){

        if(day==p.size()) return 0;
          if(dp[day][buy]!=-1) return dp[day][buy]; 
        if(buy){
            return dp[day][buy]=max(-p[day]+f(day+1,!buy,p,dp),f(day+1,buy,p,dp));
        }

        return dp[day][buy]=max(p[day]+f(day+1,!buy,p,dp),f(day+1,buy,p,dp));
     }
    int maxProfit(vector<int>& p) {
         int n=p.size();
        // int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans= f(0,1,p,dp);
        return ans==-1e9?0:ans;
    }
};