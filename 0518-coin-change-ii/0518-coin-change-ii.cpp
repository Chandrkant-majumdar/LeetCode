class Solution {
public:
   int f(int i,int a, vector<vector<int>>&dp,vector<int>& c){
    
    
    if(i==0){ 
           
            if(a==0 || a==c[i]) return 1;
            
            if(a%c[i]==0) return 1;
        
      
        return 0;
        
    }
    if(dp[i][a]!=-1) return dp[i][a];
    int tk=(a>=c[i])?f(i,a-c[i],dp,c):0;
    int nt=f(i-1,a,dp,c);
    return dp[i][a]=tk+nt;
   }
    int change(int sum,vector<int>& arr) {
         int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        int ans=f(n-1,sum,dp,arr);
        return ans==1e9?-1:ans;
    }
};