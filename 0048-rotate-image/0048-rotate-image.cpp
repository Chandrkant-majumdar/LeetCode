class Solution {
public:
    void rotate(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i<j){
                    swap(ma[i][j],ma[j][i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            reverse(ma[i].begin(),ma[i].end());
        }
    }
};