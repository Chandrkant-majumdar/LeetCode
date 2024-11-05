class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
        int ind=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[ind++]=nums[i];
            }else{
                c++;
            }
        }
        int n=nums.size()-1;
        while(c--){
           nums[n--]=0;
        }
    }
    void moveZeroes(vector<int>& nums) {
        int ind=0;
        for(auto &x:nums){
            if(x!=0){
                swap(x,nums[ind++]);
            }
        }
    }
    
};