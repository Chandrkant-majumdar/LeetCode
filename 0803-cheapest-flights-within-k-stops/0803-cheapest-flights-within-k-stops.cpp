class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
          vector<pair<int,int>>adj[n];
          for(auto x:f){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            adj[u].push_back({v,w});
          }
          queue<pair<int,pair<int,int>>>q;
          q.push({0,{src,0}});
          vector<int>dis(n,1e9);
          dis[src]=0;
          while(!q.empty()){
            int stp=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            
            if(stp>k) continue;
            for(auto nbr:adj[node]){
                int v=nbr.first;
                int edw=nbr.second;
                if(cost+edw<dis[v] && stp<=k){
                    dis[v]=cost+edw;
                    q.push({stp+1,{v,cost+edw}});
                }

            }
          }
          if(dis[dst]==1e9) return -1;

          return dis[dst];
    }
};