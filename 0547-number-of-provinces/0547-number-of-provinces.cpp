class Solution {
public:
    
    void dfs(int node,vector<int>&vis,vector<int>adj[]){

        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x]){
                vis[x]=1;
                dfs(x,vis,adj);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& e) {
        int n=e.size();
        int m=e[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(e[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                 }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};