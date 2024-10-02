class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int>s(arr.begin(),arr.end());
        int rank=1;
        unordered_map<int,int>m;
        for(auto x:s){
           m[x]=rank++;
        }
        for(auto &x:arr){
            x=m[x];
        }
        return arr;
    }
};