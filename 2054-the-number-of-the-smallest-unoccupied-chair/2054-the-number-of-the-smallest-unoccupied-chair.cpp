class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int arrival_target=times[targetFriend][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>exit_chair;
        priority_queue<int,vector<int>,greater<int>>lowestchair;
        sort(times.begin(),times.end());
        for(int i=0;i<times.size();i++){
            lowestchair.push(i);
        }
        for(int i=0;i<times.size();i++){
            while(!exit_chair.empty()&&exit_chair.top().first<=times[i][0]){
                lowestchair.push(exit_chair.top().second);
                exit_chair.pop();
            }
            int chair=lowestchair.top();
            lowestchair.pop();
            if(times[i][0]==arrival_target)return chair;
            exit_chair.push({times[i][1],chair});
        }
        return -1;
    }
};