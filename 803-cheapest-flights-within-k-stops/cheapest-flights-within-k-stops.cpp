class Solution {
public:

    typedef pair<int,pair<int,int>> piii;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>ans(n,1e9);
        ans[src] = 0 ;

        priority_queue<piii,vector<piii>,greater<piii>>pq;
        pq.push({0,{0,src}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int stops = it.first ;
            if(stops == k+1) break;
            int dist = it.second.first;
            int node = it.second.second;

            for(auto it :adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist + wt < ans[v]){
                    ans[v] = dist+wt;
                    pq.push({stops+1,{ans[v],v}});
                }
            }
        }
        if(ans[dst] == 1e9) return -1 ;
        return ans[dst];

    }
};