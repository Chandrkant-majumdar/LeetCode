class Solution {
public:


void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>& g){
     vis[r][c]=1;
     int dr[]={-1,+1,0,0};
     int dc[]={0,0,-1,+1};
     for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nc>=0 && nr<g.size() && nc<g[0].size() && !vis[nr][nc] && g[nr][nc]){
                dfs(nr,nc,vis,g);
        }
     }
}

int numEnclaves(vector<vector<int>>& g){
      int n=g.size();
      int m=g[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
      for(int i=0;i<n;i++){
         if(!vis[i][0] && g[i][0]){
            dfs(i,0,vis,g);
         }
         if(!vis[i][m-1] && g[i][m-1]){
                dfs(i,m-1,vis,g);
         }
      }
      for(int i=0;i<m;i++){
          if(!vis[0][i] && g[0][i]){
             dfs(0,i,vis,g);
         }
         if(!vis[n-1][i] && g[n-1][i]){
            dfs(n-1,i,vis,g);
         }
      }
     int ans=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=1 && g[i][j]==1 ){
                ans++;
            }
        }
      }
      return ans;

}





//    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& g){
//     vis[i][j]=1;
//     int n=vis.size();
//     int m=vis[0].size();
//     int r[]={0,0,-1,+1};
//     int c[]={-1,+1,0,0};
//     for(int k=0;k<4;k++){
//         int nr=i+r[k];
//         int nc=j+c[k];
//         if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && g[nr][nc]==1){
//             dfs(nr,nc,vis,g);
//         }
//     }
//    }
//     int numEnclaves(vector<vector<int>>& g) {
//         int n=g.size();
//         int m=g[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
//         for(int i=0;i<n;i++){
//             if(!vis[i][0]&&g[i][0]==1){
//                 dfs(i,0,vis,g);
//             }
//             if(!vis[i][m-1] && g[i][m-1]==1){
//                 dfs(i,m-1,vis,g);
//             }
//         }
//         for(int i=0;i<m;i++){
//             if(!vis[0][i]&&g[0][i]==1){
//                 dfs(0,i,vis,g);
//             }
//             if(!vis[n-1][i] && g[n-1][i]==1){
//                 dfs(n-1,i,vis,g);
//             }
//         }
//         int c=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j]==0 && g[i][j]==1){
//                     c++;
//                 }
//             }
//         }
//         return c;
//     }
};