class Solution {
public:
    int majorityElement1(vector<int>& nums) {
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
    int majorityElement(vector<int>& nums) {
        int c=0,e=-1;
        for(auto x:nums){
            if(c==0){
                e=x;
            }
            if(e==x) c++;
            else c--;
        }
        return e;
    }
};