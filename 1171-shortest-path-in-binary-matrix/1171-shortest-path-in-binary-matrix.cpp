class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        if(g[0][0]!=1)
        q.push({{0,0},0});
        vis[0][0]=1;
        while(!q.empty()){
            auto it=q.front();
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;
            q.pop();
            if(r==n-1 && c==m-1){
                return d+1;
            }
            // if(r==n-1 && c==m-1 && g[r][c]==1){
            //     return -1;
            // }
            for(int i=-1;i<=1;i++){
                for(int  j=-1;j<=1;j++){
                    int nr=r+i;
                    int nc=c+j;
                    if(nr>=0 && nc>=0 && nr<n && nc<m && g[nr][nc]==0 && !vis[nr][nc]){
                         vis[nr][nc]=1;
                        q.push({{nr,nc},d+1});
                    }
                }
            }
        }
        return -1;
    }
};