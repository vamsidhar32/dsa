class Solution {
public:

    void dfs( int start , vector<int> adj[] , vector<int> &vis){
        vis[start] = 1 ;

        for( auto it : adj[start]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> adj[n+1];
        for(int i =0 ; i< n ;i++){
            for(int j =0 ;j < n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        int count =0  ;
        vector<int> vis(n+1,0);
        for(int i =0 ; i<=n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }

        return count-1 ;
    }
};