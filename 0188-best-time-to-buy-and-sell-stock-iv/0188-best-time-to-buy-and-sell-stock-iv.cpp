class Solution {
public:
    int f(int i,int b,int c,vector<int>& p,vector<vector<vector<int>>>&dp){
         int n=p.size();
        if(i==n || c==0) return 0;

        int pro=0;
        if(dp[i][b][c]!=-1) return dp[i][b][c];
        if(b){
            pro=max(-p[i]+f(i+1,!b,c,p,dp),f(i+1,b,c,p,dp));
        }else{
            pro=max(p[i]+f(i+1,!b,c-1,p,dp),f(i+1,b,c,p,dp));
        }
        return dp[i][b][c]= pro;
    }
    int maxProfit(int k,vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,p,dp);
    }
};