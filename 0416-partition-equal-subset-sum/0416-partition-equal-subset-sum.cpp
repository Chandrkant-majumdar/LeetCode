class Solution {
public:
bool f(int i,int sum,vector<int>& arr,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(i==0){
            return (sum==arr[i]);
            
        }
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool tk=(sum>=arr[i])?f(i-1,sum-arr[i],arr,dp):0;
        bool nt=f(i-1,sum,arr,dp);
        
        return dp[i][sum]=tk|| nt;
    }
    bool canPartition(vector<int>& arr) {
        int sum=0;
        for(auto x:arr){
            sum+=x;
        }
        if(sum&1) return false;
        sum=sum/2;
        
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
};