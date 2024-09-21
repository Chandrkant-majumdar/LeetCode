class Solution {
public:
     int f(int i,int b,vector<int>& p,vector<vector<int>>&dp,int fee){
        int n=p.size();
        if(i>=n) return 0;
        int pro=0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b){
            pro=max(-p[i]-fee+f(i+1,!b,p,dp,fee),f(i+1,b,p,dp,fee));
        }else{
            pro=max(p[i]+f(i+1,!b,p,dp,fee),f(i+1,b,p,dp,fee));
        }
        return dp[i][b]=pro;
     }
    int maxProfit(vector<int>& p,int fee) {
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,p,dp,fee);
    }
};