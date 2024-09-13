class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int V=g.size();
        vector<int>in(V,0);
        vector<int>adj[V];
        for(int i=0;i<V;i++){
              for(auto x:g[i]){
                adj[x].push_back(i);
                in[i]++;
              }
        }
        queue<int>q;

        for(int i=0;i<V;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                in[x]--;
                if(in[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};