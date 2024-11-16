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
   bool bfs(int src,vector<vector<int>>& g,vector<int>&vis,vector<int>&c){
            queue<int>q;
            q.push(src);
            vis[src]=1;
            c[src]=0;
            while(!q.empty()){
                 int node=q.front();
                 q.pop();
                 for(auto x:g[node]){
                    if(!vis[x]){
                        c[x]=!c[node];
                        vis[x]=1;
                        q.push(x);
                    }else if(c[x]==c[node]){
                        return false;
                    }
                 }
            }
            return true;
   }
   bool isBipartite(vector<vector<int>>& g){
         int n=g.size();
        vector<int>vis(n,0);
         vector<int>c(n,-1);
        //  queue<int>q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,g,vis,c)==false) return false;
            }
        }
        return true;
         
   }
    bool isBipartite1(vector<vector<int>>& g) {
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