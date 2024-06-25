class Solution {
public:


    bool dfs(int i , vector<vector<int>>&graph, int color,vector<int>&vis,vector<int>&colour){

        vis[i] = 1 ;
        colour[i] = color;
        for(auto it:graph[i]){
            if(vis[it] == 0){
                if(dfs(it,graph,!color,vis,colour) == false ) return false ;
                //vis[i] = 1 ;
            }
            else if(colour[it] == color) return false ;
        }

        return true ;

    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int>vis(n,0);
        vector<int>colour(n,-1);
        for(int i = 0 ; i < n ;i++){
            int color = 0 ;
            if(vis[i] ==0){
                bool left = dfs(i,graph,color,vis,colour);
                if(left == false ) return false ;
            }
        }
        return true;
    }
};