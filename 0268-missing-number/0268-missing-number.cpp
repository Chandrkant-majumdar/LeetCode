class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int>hash(nums.size()+1,0);
        for(auto x:nums){
            hash[x]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==0) return i;
        }
        return -1;
    }
};