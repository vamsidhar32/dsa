class Solution {
public:

    void dfs( int start , vector<vector<int>> isConnected , vector<int> &vis){
        vis[start] = 1 ;

        for(int it =0 ; it < isConnected.size(); it++){
            if(isConnected[start][it] == 0) continue ;
            if(!vis[it]){
                dfs(it,isConnected,vis);
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
        for(int i =0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                count++;
            }
        }

        return count ;
    }
};