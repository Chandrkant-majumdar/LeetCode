class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        int n=nums.size();
        for(auto x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>floor(n/2)) return x.first;
        }

        return -1;
    }
};