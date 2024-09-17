class Solution {
public:
    int f(int i,int c,vector<int>& co, vector<vector<int>>&dp){

        if(i==0){
            
            if(c%co[0]==0){
                return c/co[0];
            }
            else
             return 1e9;

        }

        if(dp[i][c]!=-1) return dp[i][c];

        int tk=(c>=co[i])?1+f(i,c-co[i],co,dp):1e9;
        int nt=f(i-1,c,co,dp);
        return dp[i][c]=min(tk,nt);
    }
    int coinChange(vector<int>& co, int c) {
        int n=co.size();
        vector<vector<int>>dp(n,vector<int>(c+1,-1));
        if(f(n-1,c,co,dp)==1e9) return -1;
        
        return f(n-1,c,co,dp);
    }
};