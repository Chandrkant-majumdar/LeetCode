class Solution {
public:
    vector<int> findOrder(int nc, vector<vector<int>>& pre) {
        int V=nc;
           vector<int>vis(nc,0),id(nc,0);
           vector<int>adj[nc];
           for(auto x:pre){
            adj[x[1]].push_back(x[0]);
           }
       for(int i=0;i<V;i++){
           for(auto x:adj[i]){
               id[x]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++){
           if(id[i]==0){
               q.push(i);
           }
       }
       vector<int>ans;
       while(!q.empty()){
           int node=q.front();
           ans.push_back(node);
           q.pop();
           for(auto nbr:adj[node]){
               id[nbr]--;
               if(id[nbr]==0){
                   q.push(nbr);
               }
           }
       }
       
       
    //    sort(ans.begin(),ans.end());
      if(ans.size()==V) return ans;
       return {};
    }
};