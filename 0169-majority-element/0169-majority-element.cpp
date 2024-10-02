class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>floor(nums.size()/2)){
                return x.first;
            }
        }
        return -1;
    }
};