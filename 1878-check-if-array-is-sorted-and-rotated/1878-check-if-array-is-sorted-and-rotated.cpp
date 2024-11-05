class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<=n;i++){
           
            if(nums[(i-1)%n]>nums[i%n]) c++;
        }
        return c==1 || c==0;
    }
};