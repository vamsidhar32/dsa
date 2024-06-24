class Solution {
public:

    void bfs(int i , int j , vector<vector<char>>&grid , vector<vector<int>>&vis,vector<int>&delrow,vector<int>&delcol){

        queue<pair<int,int>>q ;
        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1 ;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i <q.size(); i++){
                pair<int,int>p = q.front();
                q.pop();
                int row =p.first;
                int col = p.second ;
                for(int i =0 ; i <4 ; i++){
                    int actrow = row+delrow[i];
                    int actcol = col+delcol[i];
                    if(actrow >= 0 && actrow <n && actcol>=0 && actcol <m){
                    if(grid[actrow][actcol] == '1' && vis[actrow][actcol] == 0){
                        q.push({actrow,actcol});
                        vis[actrow][actcol] = 1 ;
                    }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0 ;

        vector<vector<int>>vis(n,vector<int>(m,0));


        vector<int>delrow{0,0,-1,1};
        vector<int>delcol{-1,1,0,0};
        for(int i = 0 ; i <n ; i++){
            for(int j = 0 ;j <m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    bfs(i,j,grid,vis,delrow,delcol);
                    count++;
                }
            }
        }
        return count;
    }
};