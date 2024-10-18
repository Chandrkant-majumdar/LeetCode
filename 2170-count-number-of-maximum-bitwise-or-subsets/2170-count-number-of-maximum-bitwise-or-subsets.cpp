class Solution {
    int n;
    int maxV;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        maxV = 0;
        for(auto i:nums)
            maxV |= i;
        return DFS(nums, 0, 0);
    }
    int DFS(vector<int>& nums, int value, int ind){
        if(value == maxV)
            return 1<<(n-ind);
        if(ind == n)
            return 0;
        return DFS(nums, value|nums[ind++], ind) + 
               DFS(nums, value, ind);
    }
};