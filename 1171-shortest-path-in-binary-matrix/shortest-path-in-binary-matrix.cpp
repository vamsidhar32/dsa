class Solution {
public:
    typedef pair<int,pair<int,int>> piii;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 ){
            return grid[0][0] == 1 ? -1 : 1;
        }

        if(grid[0][0] == 1) return -1 ;

        vector<vector<int>>ans(n,vector<int>(m,1e9));
        ans[0][0] = 1 ;

        queue<piii>q;
        q.push({1,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first ;
            int row = it.second.first;
            int col = it.second.second;
            for(int i = -1 ; i<=1 ;i++){
                for(int j = -1 ;j<=1;j++){
                    if(i==0 && j==0) continue ;
                    int newrow = row+i;
                    int newcol = col+j;
                    if(newrow>=0 && newrow <n&&newcol >=0 && newcol <m){
                        if(grid[newrow][newcol] == 0){
                            if(dist+1 < ans[newrow][newcol]){
                                ans[newrow][newcol] = dist+1;
                                q.push({dist+1,{newrow,newcol}});
                            }
                        }
                    }
                }
            }
        }
        if(ans[n-1][n-1] == 1e9) return -1 ;
        return ans[n-1][n-1];
    }
};