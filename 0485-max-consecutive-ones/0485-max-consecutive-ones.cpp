class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int ans=INT_MIN;
       int c=0;
       for(auto x:nums){
           if(x==1){
             c++;
           }else{
            c=0;
           }
           ans=max(ans,c);
       }
        return ans;
    }
};