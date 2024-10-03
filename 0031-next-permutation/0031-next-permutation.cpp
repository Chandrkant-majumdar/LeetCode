class Solution {
public:
    void nextPermutation1(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            // return nums;
        }else{
          for(int j=nums.size()-1;j>=ind+1;j--){
            if(nums[j]>nums[ind]){
                swap(nums[j],nums[ind]);
                
                break;
            }           

        }
        reverse(nums.begin()+ind+1,nums.end());
        }
        
        
        // return nums;
    }
};