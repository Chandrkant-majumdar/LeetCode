class Solution {
public:
     int f(int i ,int j,string &s1, string &s2,vector<vector<int>>&dp){

         if(i==0) return j;
         if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]){
            return f(i-1,j-1,s1,s2,dp);
        }
        return  dp[i][j]=min({1+f(i,j-1,s1,s2,dp),1+f(i-1,j,s1,s2,dp),1+f(i-1,j-1,s1,s2,dp)});
     }
    int minDistance(string s1, string s2) {
          int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=f(n,m,s1,s2,dp);
        return ans;
    }
};