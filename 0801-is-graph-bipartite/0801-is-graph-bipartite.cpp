class Solution {
public:
    bool dfs(int node,int c,vector<int>adj[],vector<int>&col){
        col[node]=c;


        for(auto nbr:adj[node]){
            if(col[nbr]==-1){
                if(dfs(nbr,!c,adj,col)==false) return false;
            }
            else if(c==col[nbr]){
                  return false;
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& g) {

        int n=g.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto x:g[i]){
                adj[i].push_back(x);
            }
        }
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(dfs(i,0,adj,col)==false) return false;
            }
        }
        return true;
    }
};