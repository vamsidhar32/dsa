class Solution {
public:
    typedef pair<int,int> pii;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<pii> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<vector<int>>matrix (n,vector<int>(n,1e8));
        for(int i =0 ; i <n ; i++){
            matrix[i][i] = 0;
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(int i = 0 ; i < n ; i++){
            pq.push({0,i});

            while(!pq.empty()){
                pii top = pq.top();
                pq.pop();
                int dist = top.first ;
                int node = top.second;

                for(auto it : adj[node]){
                    int adjnode = it.first ;
                    int wt = it.second;
                    if(dist + wt < matrix[i][adjnode]){
                        matrix[i][adjnode] = dist+wt;
                        pq.push({dist+wt,adjnode});
                    }
                }
            }
        }
        int city = -1 ;
        int mincities = n+1;
        for(int i=0 ; i <n ; i++){
            int count = 0 ;
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= mincities){
                mincities = count ; 
                city = i ;
            }
        }

        return city ;


    }
};