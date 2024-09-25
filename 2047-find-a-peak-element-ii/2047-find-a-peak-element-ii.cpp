class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int dr[]={0,0,-1,+1};
        int dc[]={-1,+1,0,0};
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool peak=true;
                for(int k=0;k<4;k++){
                    
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && (mat[i][j]<mat[nr][nc])){
                        
                            peak=false;
                        }
                    }
                    if(peak) return {i,j};
                }
                

            }
        
        return {};
    }
};