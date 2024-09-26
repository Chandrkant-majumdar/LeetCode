class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        using ll = long long;

        // Adjacency list representation of the graph
        vector<pair<int, int>> adj[n];
        for (auto &x : roads) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Distance and ways arrays
        vector<ll> dis(n, LLONG_MAX);  // Use long long to handle large distances
        dis[0] = 0;
        vector<int> way(n, 0);  // Ways to reach each node
        way[0] = 1;

        // Min-heap (priority queue) to store (distance, node)
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});  // {distance, node}

        while (!pq.empty()) {
            ll cost = pq.top().first;  // Current distance from the source
            int node = pq.top().second;  // Current node
            pq.pop();

            // Traverse neighbors of the current node
            for (auto &x : adj[node]) {
                int neighbor = x.first;
                ll edgeWeight = x.second;

                // If a shorter path is found
                if (cost + edgeWeight < dis[neighbor]) {
                    dis[neighbor] = cost + edgeWeight;
                    pq.push({dis[neighbor], neighbor});
                    way[neighbor] = way[node];  // All ways to the current node lead to this node
                }
                // If another shortest path is found
                else if (cost + edgeWeight == dis[neighbor]) {
                    way[neighbor] = (way[neighbor] + way[node]) % MOD;  // Add the number of ways (modulo MOD)
                }
            }
        }

        // Return the number of ways to reach the last node (n-1) modulo MOD
        return way[n-1] % MOD;
    }
};
