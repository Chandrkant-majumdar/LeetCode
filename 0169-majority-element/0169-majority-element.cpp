class Solution {
public:
    int majorityElement(vector<int>& nums) {
            int c=0,ele;
            for(auto x:nums){
                if(c==0){
                    ele=x;
                    c=1;
                }
                else if(x==ele) c++;
                else c--;
            }
            // c=0;
            // for(auto x:nums){
            //     if(x==ele) c++;
            // }
            return ele;

    }
    int majorityElement1(vector<int>& nums) {
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