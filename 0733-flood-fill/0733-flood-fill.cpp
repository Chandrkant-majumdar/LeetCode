class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&ans,vector<vector<int>>&image,int ic,int color){
        ans[i][j]=color;
        int n=image.size();
        int m=image[0].size();
        int dr[]={0,0,-1,+1};
        int dc[]={-1,+1,0,0};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==ic && ans[nr][nc]!=color){
                 dfs(nr,nc,ans,image,ic,color);
            }
        }
    }
    vector<vector<int>> floodFill1(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        
        int ic=image[sr][sc];
        dfs(sr,sc,ans,image,ic,color);
        return ans;
    }
    //             Method 2 (using Bfs)
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int color){
                vector<vector<int>>ans;
                ans=im;
                int n=im.size();
                int m=im[0].size();
                int col=im[sr][sc];
                vector<vector<int>>vis(n,vector<int>(m,0));
                queue<pair<int,int>>q;
                q.push({sr,sc});
                int row[]={0,0,-1,+1};
                int colm[]={-1,+1,0,0};
                while(!q.empty()){
                    int r=q.front().first;
                    int c=q.front().second;
                    ans[r][c]=color;
                    vis[r][c]=1;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nr=r+row[i];
                        int nc=c+colm[i];
                        if(nr>=0 && nc>=0 && nr<n && nc<m&& !vis[nr][nc] && ans[nr][nc]==col){
                            ans[nr][nc]=color;
                            q.push({nr,nc});
                        }
                    }
                }

                return ans;
    }
};