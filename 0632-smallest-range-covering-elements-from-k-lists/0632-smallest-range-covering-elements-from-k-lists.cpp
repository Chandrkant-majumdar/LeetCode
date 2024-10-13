class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<P,vector<P>,greater<P>> pqmin;
        int maxv = INT_MIN;
        
        for(int i = 0; i < n; i++){
            pqmin.push({nums[i][0], {i, 0}});
            maxv = max(maxv, nums[i][0]);
        }
        
        int minv = pqmin.top().first;
        int diff = INT_MAX;
        int start = -1, end = -1;
        
        while(true){
            auto curr = pqmin.top();
            pqmin.pop();
            minv = curr.first;
            int mini = curr.second.first;
            int minj = curr.second.second;

            if(maxv - minv < diff) {
                diff = maxv - minv;
                start = minv;
                end = maxv;
            }
            
            if(minj + 1 >= nums[mini].size()) break;
            
            pqmin.push({nums[mini][minj + 1], {mini, minj + 1}});
            maxv = max(maxv, nums[mini][minj + 1]);
        }
        
        return {start, end};
    }
};