class Solution {
public:
    bool bfs(int i , vector<vector<int>>&graph,vector<int>&colour,int color){
        queue<int>q;
        q.push(i);
        colour[i] = color;
        while(!q.empty()){
            int size = q.size();
            for(int i =0 ; i <size ; i++){
                int top = q.front();
                q.pop();

                for(auto it :graph[top]){
                    if(colour[it] == -1){
                        colour[it] = !colour[top];
                        q.push(it);
                    }
                    else if(colour[it] == colour[top]) return false ;
                }
            }
        }

        return true ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colour(n,-1);
        for(int i = 0 ; i <n ;i++){
            if(colour[i] == -1){
                int color = 0 ;
                bool left = bfs(i,graph,colour,color);
                if(left == false) return false ;
            }
        }

        return true;
    }
};