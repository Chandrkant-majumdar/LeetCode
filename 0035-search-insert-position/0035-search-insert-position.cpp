class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int l=0,h=nums.size()-1;int ans=nums.size();
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==x) return mid;
            else if(nums[mid]<x){
               
                l=mid+1;
            }else{
                 ans=mid;
                h=mid-1;
            }
        }
        return ans;
    }
};