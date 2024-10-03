class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ma[i][j]==0){
                    row[i]=1;
                    col[j]=1;               
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){
                    ma[i][j]=0;
                }
            }
        }
    }
};