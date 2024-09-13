class Solution {
public:
    vector<int> xorQueries(vector<int>& a, vector<vector<int>>& q) {
        vector<int>ans;
        for(auto x:q){
              int t=0;
            for(int i=x[0];i<=x[1];i++){
                   t=t^a[i];
            }
           
            ans.push_back(t);
        }
        return ans;
    }
};