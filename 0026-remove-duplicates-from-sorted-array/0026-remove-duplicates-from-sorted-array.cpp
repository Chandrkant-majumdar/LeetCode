class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
         if(n==1) return 1;
        while(j<n){
           if(nums[j]!=nums[i]) nums[++i]=nums[j];

           j++;
        }
        return i+1;
    }
};