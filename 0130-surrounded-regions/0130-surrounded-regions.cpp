class Solution {
public:
   void dfs(int r,int c,vector<vector<char>>& b,vector<vector<int>>&vis){
           vis[r][c]=1;

           int dr[]={0,0,-1,+1};
           int dc[]={-1,+1,0,0};
           for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<b.size() && nc<b[0].size()  && b[nr][nc]=='O' && !vis[nr][nc] ){
                dfs(nr,nc,b,vis);
            }
           }

   }

 void solve(vector<vector<char>>& b) {

        int n=b.size();
        int m=b[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<m;i++){
            if(b[0][i]=='O'){
                if(!vis[0][i])
                dfs(0,i,b,vis);
            }
            if(b[n-1][i]=='O'){
                 if(!vis[n-1][i])
                dfs(n-1,i,b,vis);
            }
        }
        for(int i=0;i<n;i++){
            if(b[i][0]=='O'){
                if(!vis[i][0])
                dfs(i,0,b,vis);
            }
            if(b[i][m-1]=='O'){
                 if(!vis[i][m-1])
                dfs(i,m-1,b,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=1){
                    b[i][j]='X';
                }
            }
        }


 }
//    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&b){
//     int n=vis.size();
//     int m=vis[0].size();
//          vis[i][j]=1;
//          int dr[]={0,0,-1,+1};
//          int dc[]={-1,+1,0,0};
//          for(int k=0;k<4;k++){
//             int nr=i+dr[k];
//             int nc=j+dc[k];
//             if(nr>=0&& nr<n &&nc>=0 && nc<m && vis[nr][nc]==0 && b[nr][nc]=='O'){

//                 dfs(nr,nc,vis,b);
//             }
//          }
//    }
    // void solve(vector<vector<char>>& b) {
    //     int n=b.size();
    //     int m=b[0].size();
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     for(int i=0;i<m;i++){
    //         if(b[0][i]=='O'){
    //             if(!vis[0][i])
    //             dfs(0,i,vis,b);
    //         }
    //     }
    //     for(int i=0;i<m;i++){
    //         if(b[n-1][i]=='O'){
    //             if(!vis[n-1][i])
    //             dfs(n-1,i,vis,b);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(b[i][0]=='O'){
    //             if(!vis[i][0])
    //             dfs(i,0,vis,b);
    //         }
    //     }
    //     for(int i=0;i<n;i++){
    //         if(b[i][m-1]=='O'){
    //             if(!vis[i][m-1])
    //             dfs(i,m-1,vis,b);
    //         }
    //     }

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(vis[i][j]!=1){
    //                 b[i][j]='X';
    //             }
    //         }
    //     }

    // }
};