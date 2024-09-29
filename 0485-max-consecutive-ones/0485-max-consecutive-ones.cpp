class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int sum=0;
        for(auto x:nums){
            if(x!=0){
                sum+=x;
            }else{
               
                sum=0;
            }
             ans=max(sum,ans);
        }
        return ans;
    }
};