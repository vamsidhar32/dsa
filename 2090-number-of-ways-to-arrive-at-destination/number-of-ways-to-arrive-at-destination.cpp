class Solution {
public:
    typedef pair<long long, int> pi;  // Use long long for the distance
    #define mod 1000000007
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];

        // Build adjacency list
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> count(n, 0);
        count[0] = 1;
        
        vector<long long> ans(n, 1e18);  // Use long long to store large distances
        ans[0] = 0;

        priority_queue<pi, vector<pi>, greater<pi>> pq; 
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto& it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist + wt < ans[v]) {
                    ans[v] = dist + wt;
                    pq.push({ans[v], v});
                    count[v] = count[node] % mod;
                } else if (dist + wt == ans[v]) {
                    count[v] = (count[v] + count[node]) % mod;
                }
            }
        }

        return count[n - 1];
    }
};
