class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
       for(int i=0;i<n;i++){
        int  sum=0;
        for(int j=i;j<n;j++){
            
            // for(int k=i;k<=j;k++){
                sum+=nums[j];
            // }
            if(sum==k) c++;
        }
       }
       return c;
    }
};