class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=1;i<=n;i++){
             if(nums[i-1]>nums[(i%n)]){
                c++;
             }
        }
        if(c>1) return false;
        return true;
    }
};