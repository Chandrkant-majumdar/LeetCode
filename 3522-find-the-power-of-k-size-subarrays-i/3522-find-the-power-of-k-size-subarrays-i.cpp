class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(n - k + 1, -1);
    
    for (int i = 0; i <= n - k; i++) {
        bool isConsecutive = true;
        for (int j = 1; j < k; j++) {
            if (nums[i + j] != nums[i + j - 1] + 1) {
                isConsecutive = false;
                break;
            }
        }
        
        if (isConsecutive) {
            ans[i] = nums[i + k - 1];
        }
    }
    
    return ans;
}
};