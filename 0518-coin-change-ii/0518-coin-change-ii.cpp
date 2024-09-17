class Solution {
public:
    int f(int i,int A,vector<int>& c,vector<vector<int>>&dp){
         
         if(i==0){
            if(A%c[i]==0) return 1;
            else
            return 0;
         }
        if(dp[i][A]!=-1) return dp[i][A];
        int tk=(A>=c[i])?f(i,A-c[i],c,dp):0;
        int nt=f(i-1,A,c,dp);

        return dp[i][A]=(tk+nt);
    }
    int change(int A, vector<int>& c) {
        int n=c.size();
        vector<vector<int>>dp(n,vector<int>(A+1,-1));
        return f(n-1,A,c,dp);
    }
};