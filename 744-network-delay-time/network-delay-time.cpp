class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];

        for(auto it :times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>ans(n+1,1e9);
        ans[k] = 0 ;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});

        while(!q.empty()){
            pair<int,int>p = q.top();
            q.pop();
            int dis = p.first ;
            int node = p.second;
            for(auto it :adj[node]){
                int v = it.first ;
                int wt = it.second;
                if(dis+wt < ans[v]){
                    ans[v] = dis+wt;
                    q.push({ans[v],v});
                }
            }
        }
        int maxx = INT_MIN;
        for(int i =1 ; i<=n ; i++){
            if(ans[i] == 1e9) return -1;
            maxx = max(maxx,ans[i]);
        }

        return maxx;
    }
};