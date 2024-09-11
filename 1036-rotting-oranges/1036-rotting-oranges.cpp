class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& g){
        int n=g.size();
        int m=g[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0,tc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!=0) tc++;
                if(g[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        if(tc==0) return 0;
        int ans=INT_MIN;
        int dr[]={0,0,-1,+1};
        int dc[]={-1,+1,0,0};
        int o=1;
        
        while(!q.empty()){
            auto t=q.front();
            int r=t.first.first;
            int c=t.first.second;
            int time=t.second;
             ans=max(ans,time);
             q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 &&nr< n && nc>=0 && nc<m && g[nr][nc]&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    o++;
                    q.push({{nr,nc},time+1});
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return ans;
        
    }
    // int orangesRotting(vector<vector<int>>& g) {
    //     int n=g.size();
    //     int m=g[0].size();
    //     int ti=0;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     queue<pair<pair<int,int>,int>>q;
    //     int c=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(g[i][j]==2){
    //                 vis[i][j]=2;
    //                 q.push({{i,j},0});
    //             }else{
    //                 vis[i][j]=0;
    //             }
    //         }
    //     }
    //     int dr[]={0,0,-1,+1};
    //     int dc[]={-1,+1,0,0};
    //     while(!q.empty()){
    //              int row=q.front().first.first;
    //              int col=q.front().first.second;
    //              int t=q.front().second;
    //              ti=max(ti,t);
    //              q.pop();
    //              for(int i=0;i<4;i++){
    //                   int nr=row+dr[i];
    //                   int nc=col+dc[i];
    //                   if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && g[nr][nc]==1){
    //                     vis[nr][nc]=2;
    //                     q.push({{nr,nc},t+1});
    //                   }
    //              }
    //     }
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(vis[i][j]!=2&& g[i][j]==1) return -1;
    //         }
    //     }
    //     return ti;
    // }
};