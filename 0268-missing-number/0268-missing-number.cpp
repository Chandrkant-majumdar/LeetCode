class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+1,0);
        for(auto x:nums){
            v[x]++;
        }
        int ans;
        for(int i=0;i<=n;i++){
            if(v[i]==0) {ans=i;break;}
        }

        return ans;
    }
    int missingNumber(vector<int>& nums){
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int ans=(n*(n+1))/2-sum;
        return ans;
    }
};