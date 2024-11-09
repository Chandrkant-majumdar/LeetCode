class Solution {
public:
   int f(int i,int a, vector<vector<int>>&dp,vector<int>& c){
    
    if(i==0){
        
            if(a%c[i]==0) return a/c[i];
        
      
        return 1e9;
        
    }
    if(dp[i][a]!=-1) return dp[i][a];
    int tk=(a>=c[i])?1+f(i,a-c[i],dp,c):1e9;
    int nt=f(i-1,a,dp,c);
    return dp[i][a]=min(tk,nt);
   }
    int coinChange(vector<int>& arr, int sum) {
         int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=f(n-1,sum,dp,arr);
        return ans==1e9?-1:ans;
    }
};