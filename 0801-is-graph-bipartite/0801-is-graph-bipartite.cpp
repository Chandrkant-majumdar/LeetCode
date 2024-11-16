class Solution {
public:
   bool dfs(int node,int col,vector<vector<int>>& g,vector<int>&vis,vector<int>&c){
      vis[node]=1;
      c[node]=col;
      for(auto x:g[node]){
        if(!vis[x]){
            if(dfs(x,!col,g,vis,c)==false) return false;
        }else if(col==c[x]){
              return false;
        }
      }
      return true;
   }
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>vis(n,0);
         vector<int>c(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,0,g,vis,c)==false) return false;
            }
        }
        return true;
    }
};