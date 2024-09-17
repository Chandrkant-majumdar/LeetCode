class Solution {
public:
    int f(int i,int j,vector<vector<int>>&ma,vector<vector<int>>&dp){
        int n=ma.size();
        int m=ma[0].size();
        if(j<0 || j>=m){
            return 1e9;
        }
        if(i==0){
            return ma[i][j];
        } 
       if(dp[i][j]!=-1) return dp[i][j];
        int up=ma[i][j]+f(i-1,j,ma,dp);
        int ld=ma[i][j]+f(i-1,j-1,ma,dp);
        int rd=ma[i][j]+f(i-1,j+1,ma,dp);

        return dp[i][j]=min(up,min(ld,rd));


    }
    int minFallingPathSum(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
         vector<vector<int>>dp(n,vector<int>(m,0));
        // int ans=1e9;
        // for(int i=0;i<m;i++){
        //    int t=f(n-1,i,ma,dp);
        //     ans=min(ans,t);
        // }
        // return ans;
        for(int i=0;i<m;i++){
            dp[0][i]=ma[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                //  if(dp[i][j]!=-1) return dp[i][j];
                    int up=ma[i][j]+dp[i-1][j];
                    int ld=(j-1>=0)?ma[i][j]+dp[i-1][j-1]:1e9;
                    int rd=(j+1<m)?ma[i][j]+dp[i-1][j+1]:1e9;

              dp[i][j]=min(up,min(ld,rd));
            }
        }
        int ans=1e9;
        for(int i=0;i<m;i++){
           int t=dp[n-1][i];
            ans=min(ans,t);
        }
        return ans;
    }
};