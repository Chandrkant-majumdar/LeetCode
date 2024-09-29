class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(auto &x:nums){
            if(x!=0){
                swap(nums[i++],x);
            }
        }
       
    }
};