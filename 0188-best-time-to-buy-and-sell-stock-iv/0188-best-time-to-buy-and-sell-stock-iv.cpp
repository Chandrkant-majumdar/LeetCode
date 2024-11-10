class Solution {
public:
   int f(int day ,int buy,vector<int>& p,int c,vector<vector<vector<int>>>&dp){

        if(day==p.size() || c==0) return 0;
      if(dp[day][buy][c]!=-1) return dp[day][buy][c]; 
        if(buy){
            return  dp[day][buy][c]=max(-p[day]+f(day+1,!buy,p,c,dp),f(day+1,buy,p,c,dp));
        }

        return dp[day][buy][c]=max(p[day]+f(day+1,!buy,p,c-1,dp),f(day+1,buy,p,c,dp));
     }
    
    int maxProfit(int k,vector<int>& p) {
        int n=p.size();
        // int m=s2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        int c=2;
        int ans= f(0,1,p,k,dp);
        return ans==-1e9?0:ans;
    }
};