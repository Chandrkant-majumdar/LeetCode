class Solution {
public:
    vector<vector<int>> merge1(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        ans.push_back(in[0]);
        for(int i=1;i<in.size();i++){
            if(ans.back()[1]>=in[i][0]){
                ans.back()[1]=max(in[i][1],ans.back()[1]);
            }else{
                ans.push_back(in[i]);
            }
        }
        return ans;
    }
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        vector<vector<int>>ans;
        int n=in.size();

        // ans.push_back(in[0]);
        for(int i=0;i<n;i++){
            int start=in[i][0];
            int end=in[i][1];
            if(!ans.empty() && ans.back()[1]>=end){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(end>=in[j][0]){
                    end=max(end,in[j][1]);
                }else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};